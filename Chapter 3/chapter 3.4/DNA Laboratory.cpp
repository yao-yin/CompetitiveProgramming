// Implementation from https://www.hankcs.com/program/algorithm/poj-1795-dna-laboratory.html, has a better constant
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
 
using namespace std;
 
#define MAX_N   15
#define INF     0x3f3f3f3f
 
int N;
int cost[MAX_N][MAX_N];                 // 串i连接串j的长度的增量
int D[1 << MAX_N][MAX_N];               // D[字串集合][串j] := 集合尾部为j时的累计长度的最小值（也就是花费）
bool reachable[1 << MAX_N][MAX_N];      // reachable[S][j] := 既定集合（已经拼成固定的序列了）能够拼上j
string piece[MAX_N];                    // 序列
 
/**
* 更新最小值
*/
template<typename numType>
inline bool update_min(numType &old, const numType &test)
{
    if (old > test)
    {
        old = test;
        return true;
    }
    return false;
}
 
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> piece[i];
        }
 
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (i != j && piece[j].find(piece[i]) != string::npos)
                {
                    piece[i] = piece[j];         // 序列j包含i，只保留母串
                }
            }
        }
        sort(piece, piece + N);
        N = unique(piece, piece + N) - piece;   // 排重
 
        int length[MAX_N];                      // 做个软cache
        for (int i = 0; i < N; ++i)
        {
            length[i] = piece[i].length();
        }
 
        // i右连接j
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                for (int l = 0; l <= min(length[i], length[j]); ++l)
                {
                    if (piece[i].substr(length[i] - l) == piece[j].substr(0, l))
                    {
                        cost[i][j] = length[j] - l;
                    }
                }
            }
        }
 
        for (int bit = 0; bit < 1 << N; ++bit)
        {
            memset(D[bit], 0x3f, sizeof(D[bit]));
        }
        for (int i = 0; i < N; ++i)
        {
            D[1 << i][i] = length[i];
        }
        for (int bit = 0; bit < 1 << N; ++bit)
        {
            // 对每一种拼法，尝试拼接下一个串
            for (int i = 0; i < N; ++i)
            {
                if (D[bit][i] != INF)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        if (!((bit >> j) & 1))  // 如果没拼过j，尝试拼接j
                        {
                            update_min(D[bit | (1 << j)][j], D[bit][i] + cost[i][j]);
                        }
                    }
                }
            }
        }
 
        int bestLength = INF;
        for (int i = 0; i < N; ++i)
        {
            update_min(bestLength, D[(1 << N) - 1][i]);
        }
 
        memset(reachable, false, sizeof(reachable));
        for (int i = 0; i < N; ++i)
        {
            if (D[(1 << N) - 1][i] == bestLength)
            {
                reachable[(1 << N) - 1][i] = true;
            }
        }
 
        for (int bit = (1 << N) - 1; bit >= 0; --bit)
        {
            for (int i = 0; i < N; ++i)
            {
                if (reachable[bit][i])
                {
                    for (int j = 0; j < N; ++j)
                    {
                        if (i != j && ((bit >> j) & 1))
                        {
                            reachable[bit & ~(1 << i)][j] |= (D[bit & ~(1 << i)][j] + cost[j][i] == D[bit][i]);
                        }
                    }
                }
            }
        }
 
        string result = string(1, 'z' + 1);
        int appended = 0, last = -1;
        for (int i = 0; i < N; ++i)
        {
            if (reachable[1 << i][i] && update_min(result, piece[i]))
            {
                last = i;
            }
        }
 
        appended |= 1 << last;
        for (int _ = 0; _ < N - 1; ++_)
        {
            string tail = string(1, 'z' + 1);
            int key = -1;
            for (int i = 0; i < N; ++i)
            {
                if (!((appended >> i) & 1)) // 如果没有拼上过
                {
                    if (reachable[appended | (1 << i)][i]                                       // 倒着推，上一个状态可达
                            && D[appended][last] + cost[last][i] == D[appended | (1 << i)][i]   // 是最佳路径
                            && update_min(tail, piece[i].substr(length[i] - cost[last][i])))     // 字典序
                    {
                        key = i;
                    }
                }
            }
            last = key;
            appended |= 1 << key;
            result += tail;
        }
        printf("Scenario #%d:\n%s\n\n", t + 1, result.c_str());
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}
/* 
// My own implementation, might have a larger constant on POJ
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int mod = 1e9+7;
const int INF = 0x3f3f;
int t;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

vector<string> preprocess(vector<string> & v) {
    vector<string> res;
    for (int i = 0; i < v.size(); i++) {
        bool flag = true;
        for (int j = 0; j < v.size(); j++) {
            if (i == j) continue;
            if (v[j].find(v[i]) != string::npos) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res.push_back(v[i]);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int getCost(vector<string> & v, int a, int b) {
    for (int i = 0; i < v[a].size(); i++) {
        for (int j = 0; j < v[b].size(); j++) {
            if (i + j >= v[a].size()) {
                return i;
            }
            if (v[a][i+j] != v[b][j]) {
                break;
            }
        }
    }
    return v[a].size();
}

int getCnt(int x) {
    int cnt;
    while (x) {
        if (x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<string> vs = preprocess(v);
    n = vs.size();
    vector<vector<int> > g(n, vector<int> (n, INF));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            g[i][j] = getCost(vs, i, j);
            // cout << vs[i] << " " << vs[j] << ": " << g[i][j] << endl;
        }
    }

    vector<vector<int> > dp((1 << n), vector<int> (n, INF)), nxt((1 << n), vector<int> (n, -1));
    // dp[i][j]: start with j, tot stat = i
    // nxt[i][j]: the string next of j
    for (int i = 0; i < n; i ++) {
        dp[1 << i][i] = vs[i].size();
    }

    for (int st = 1; st < (1 << n); st ++) {
        if (getCnt(st) == 1) continue;
        for (int i = 0; i < n; i ++ ) {
            if ((st >> i) & 1) {
                // dp[st][i]
                int nxt_st = st - (1 << i);
                for (int j = 0; j < n; j ++) {
                    if ((nxt_st >> j) & 1) {
                        if (dp[st][i] > dp[nxt_st][j] + g[i][j]) {
                            dp[st][i] = dp[nxt_st][j] + g[i][j];
                            nxt[st][i] = j;
                        }
                    }
                }
            }
        }
    }
    int idx = -1;
    for (int i = 0; i < n; i ++) {
        if (idx == -1 || dp[(1 << n) - 1][i] < dp[(1 << n) - 1][idx]) {
            idx = i;
        }
    }
    int curr_st = (1 << n) - 1;
    string res;
    for (int i = 0; i < n-1; i ++) {
        int nxt_idx = nxt[curr_st][idx];
        res += vs[idx].substr(0, g[idx][nxt_idx]);
        curr_st -= (1 << idx);
        idx = nxt_idx;
        //cout << res << endl;
    }
    res += vs[idx];
    cout << res << endl;
}

int main() {
    quickread();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Scenario #" << i << ":" << endl;
        solve();
    }
    return 0;
}
*/

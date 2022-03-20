#ifdef _MSC_VER
#include <hash_map>
#include <hash_set>
using namespace stdext;
#define unordered_map hash_map
#define unordered_set hash_set
#else
#include <unordered_map>
#include <unordered_set>
#endif
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
const ll MAXN = 20;
const ll MAXM = 20;
ll N, M;

int dp[MAXN][1 << MAXM];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int popcount(ll x) {
    int cnt = 0;
    while (x) {
        if (x&1) cnt ++;
        x >>= 1;
    }
    return cnt;
}

vector<int> GospersHack(int k, int n)
{
    vector<int> v;
    int cur = (1 << k) - 1;
    int limit = (1 << n);
    while (cur < limit)
    {
        // do something
        v.push_back(cur);
        int lowbit = cur & -cur;
        int left = cur + lowbit;
        int right = ((left ^ cur) / lowbit) >> 2;
        cur = left | right;
    }
    return v;
}

void solve() {
    vector<vector<int>> v (N+1);
    vector<vector<int>> cache (N+1);
    for (int i = 1; i <= N; i ++) {
        cache[i] = GospersHack(i, M);
    }
    int cnt;
    for (int i = 1; i <= N; i ++) {
        cin >> cnt;
        int a;
        for (int j = 0; j < cnt; j ++) {
            cin >> a; 
            v[i].push_back(a-1);
        }
    }
    if (M < N) {
        cout << 0 << endl;
        return;
    }
    dp[0][0] = 1;

    for (int i = 1; i <= N; i ++) {
        for (ll j = 0; j < cache[i].size(); j++) {
            //cout << i << " " << st << endl;
            ll st = cache[i][j]; 
            for (int idx = 0; idx < v[i].size(); idx ++) { 
                int pos = v[i][idx];
                //cout << pos << " ";
                if ((st >> pos) & 1) {
                    dp[i][st] += dp[i-1][st - (1 << pos)];
                }
    
            }
        }
    }
    ll tot = 0;
    for (ll i = 0; i < (1 << M); i ++) {
        tot += dp[N][i];
    }
    cout << tot << endl;
}

int main() {
    quickread();
    cin >> N >> M;
    solve();
    return 0;
}

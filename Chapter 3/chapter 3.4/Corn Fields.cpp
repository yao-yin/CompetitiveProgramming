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
const ll mod = 1e9;
const int MAXM = 14;
const int MAXN = 12;
int N, M;
int stat[MAXM];
ll dp[MAXM][(1 << MAXN)];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> M >> N;
    for (int i = 1; i <= M; i ++) {
        int st = 0;
        int x;
        for (int j = 0; j < N; j ++) {
            cin >> x;
            st <<= 1;
            st |= x;   
        }
        stat[i] = st;
    } 
    dp[0][0] = 1;
    for (int i = 1; i <= M; i ++) {
        for (int st = 0; st < (1 << N); st ++) {
            if (st & (~stat[i])) {
                continue;
            }
            bool flag = false;
            for (int j = 0; j < N; j ++) {
                if (((st >> j) & 1) && ((st >> (j + 1))&1)) {
                    flag = true;
                    break;
                }
            }
            if (flag) {continue;}
            //cout << i << " " << st << endl;
            for (int prv = 0; prv < (1 << N); prv ++) {
                if (st & prv) continue;
                dp[i][st] += dp[i-1][prv];
                dp[i][st] %= mod; 
            }
        }
    }
    ll tot = 0;
    for (int st = 0; st < (1 << N); st ++) {
        tot += dp[M][st];
        tot %= mod;
    }
    cout << tot << endl;
    return 0;
}

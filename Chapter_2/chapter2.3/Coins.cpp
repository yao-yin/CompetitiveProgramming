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
const int N = 110;
const int M = 100010;
int a[N], c[N], n, m;
int dp[M];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    while (cin >> n >> m, n || m) {
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        for (int i = 1; i <= n; i ++) cin >> c[i];
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (dp[j] >= 0) dp[j] = c[i];
                else if (j < a[i] || dp[j-a[i]] <= 0) dp[j] = -1;
                else dp[j] = dp[j-a[i]] -1;
            }
        }
        int res = 0;
        for (int i = 1; i <= m; i ++) {
            if (dp[i] >= 0) res ++;
        }
        cout << res << endl;
    }
    return 0;
}

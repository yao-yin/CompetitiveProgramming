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
const int T = 1010;
const int W = 33;
int dp[T][W][3], w, t;
int apples[T];
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> t >> w;
    memset(dp, -0x3f3f3f3f, sizeof dp);
    dp[0][0][1] = 0;
    for (int i = 1; i <= t; i ++) {
        cin >> apples[i];
    }
    for (int i = 1; i <= t; i ++) {
        for (int j = 0; j <= w; j ++) {
            dp[i][j][1] = dp[i-1][j][1];
            dp[i][j][2] = dp[i-1][j][2];
            if (j > 0) {
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][2]);
                dp[i][j][2] = max(dp[i][j][2], dp[i-1][j-1][1]);
            }
            dp[i][j][apples[i]] ++;
        }
    }
    int res = 0;
    for (int i = 0; i <= w; i ++) {
        for (int j = 1; j <= 2; j ++) {
            res = max(res, dp[t][i][j]);
        }
    }
    cout << res << endl;
    return 0;
}

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
const int mod = 1e9;
const int N = 1000010;
int dp[N], n;
int nums[32];
// dp[i][j]: use (0, 1, 2, .. i) -> j dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]] + dp[i-1][j-2*nums[i]]..
// dp[i][j-nums[i]] = dp[i-1][j-nums[i]] + dp[i-1][j-2*nums[i]]
inline void quickread() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() 
{   
    for (int i = 1; i < 32; i ++) nums[i] = (1 << (i-1));
    dp[0] = 1;
    for (int i = 1; i < 32; i ++) 
    {
        for (int j = 0; j <= n; j ++) 
        {
            if (j >= nums[i]) dp[j] += dp[j-nums[i]];
            dp[j] %= mod;
            //cout << i << " " << j << ": " << dp[i][j] << endl;
        }
    }
    cout << dp[n];
}

int main() 
{
    quickread();
    cin >> n;
    solve();
    return 0;
}
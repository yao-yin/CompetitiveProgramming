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
const int N = 7;
ll nums[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    int res = 0;
    res += nums[6];
    res += nums[5];
    nums[1] = max((ll)0, nums[1] - 11*nums[5]);
    res += nums[4];
    nums[2] = max((ll)0, nums[2] - 5*nums[4]);
    ll remain_three = nums[3] % 4;
    res += nums[3] / 4;
    if(remain_three == 1) {
        ll max_two = min((ll)5, nums[2]);
        nums[2] -= max_two
    } 
    
}

int main() {
    quickread();
    while(cin >> nums[1] >> nums[2] >> nums[3] >> nums[4] >> nums[5] >> nums[6]) {
        solve();
    }
    return 0;
}

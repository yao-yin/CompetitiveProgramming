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
    bool flag1 = (nums[1] > 0);
    bool flag2 = (nums[2] > 0);
    int res = 0;
    res += nums[6];
    res += nums[5];
    if(nums[1] > 11*nums[5]) {
        nums[1] -= 11*nums[5];
    }else {
        nums[1] = 0;
        flag1 = false;
    }
    res += nums[4];
    if(nums[2] > 5*nums[4]) {
        nums[2] -= 5*nums[4];
    } else {
        flag2 = false;
        int max1 = nums[4]*20 - 4*nums[2];
        if(nums[1] > max1) nums[1] -= max1;
        else {
            nums[1] = 0;
            flag1 = false;
        }
        nums[2] = 0;
    }
    //cout << nums[1] <<" " << nums[2] << endl;
    res += (nums[3] / 4);
    int remain = nums[3] % 4;
    if(remain) {
        res ++;
        if(remain == 3) {
            if(flag2) {
                nums[2] --;
                nums[1] = max((ll)0, nums[1] - 5);
            } else {
                nums[1] = max(ll(0), nums[1] - 9);
            }
        } else if(remain == 2) {
            if(flag2) {
                ll max2 = min((ll)3, nums[2]);
                nums[2] -= max2;
                if(nums[1] > 18 - max2*4) {
                    nums[1] -= (18 - max2*4);
                } else {
                    nums[1] = 0;
                }
            }
        } else {
            if(flag2) {
                ll max2 = min(ll(5), nums[2]);
                nums[2] -= max2;
                if(nums[1] > 27 - max2*4) {
                    nums[1] -= (27 - max2*4);
                } else {
                    nums[1] = 0;
                }
            }
        }
    }
    res += (nums[2] / 9);
    if(nums[2] % 9) {
        res ++;
        nums[1] = max((ll)0, nums[1] - (36 - 4*(nums[2] % 9)));
    }
    res += (nums[1] / 36);
    res += (nums[1] % 36 != 0);
    if(res == 0) return;
    cout << res << endl;
}

int main() {
    quickread();
    while(cin >> nums[1] >> nums[2] >> nums[3] >> nums[4] >> nums[5] >> nums[6]) {
        solve();
    }
    return 0;
}

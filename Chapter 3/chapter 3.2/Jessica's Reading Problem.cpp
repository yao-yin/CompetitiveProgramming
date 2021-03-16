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
const int MAXP = 1e6+7;
int nums[MAXP], P;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    unordered_map<int, int> total;
    for (int i = 0; i < P; i ++) {
        total[nums[i]] ++;
    }
    unordered_map<int, int> curr;
    int left = 0;
    int res = P;
    for (int right = 0; right < P; right ++) {
        curr[nums[right]] ++;
        while (curr.size() == total.size()) {
            //cout << "Show curr: " << endl;
            /*for (auto & [a, b]:curr) {
                cout << a << ": " << b << endl;
            }*/
            res = min(res, right - left + 1);
            //cout << right << " & " << left << endl;
            if(--curr[nums[left]] == 0) {
                //cout << "Hey " <<left<< endl;
                curr.erase(nums[left]);
            }
            left ++;
        }
    }
    cout << res << endl;
}

int main() {
    quickread();
    cin >> P;
    for (int i = 0; i < P; i++) {
        cin >> nums[i];
    }
    solve();
    return 0;
}
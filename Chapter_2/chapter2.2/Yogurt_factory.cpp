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
const int N = 10010;
ll n,s;
ll c[N], y[N];
ll curr_idx, curr_min;
ll res;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    curr_min = 0x3f3f3f3f;
    for(int i = 0; i < n; i ++) {
        if(c[i] + (n-1 - i)*s < curr_min) {
            curr_min = c[i] + (n - i - 1)*s;
            curr_idx = i;
        }
        res += y[i]*(c[curr_idx] + s*(i - curr_idx));
    }
    cout << res << endl;
}

int main() {
    quickread();
    cin >> n >> s;
    for(int i = 0; i < n; i ++) {
        cin >> c[i] >> y[i];
    }
    solve();
    return 0;
}

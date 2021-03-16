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
const int MAXN = 10010;
int woods[MAXN];
int maxv;
int n, k;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(int x) {
    if (x == 0) return true;
    int tot = 0;
    for (int i = 0; i < n; i ++) {
        tot += woods[i] / x;
    }
    return tot >= k;
}

void solve() {
    int lo = 0;
    int hi = maxv;
    int res = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << setprecision(2) << fixed << (double)res/100.0 << endl;
}
int main() {
    quickread();
    cin >> n >> k;
    double curr;
    for (int i = 0; i < n; i ++) {
        cin >> curr;
        woods[i] = (int)(100.0*curr);
        maxv = max(maxv, woods[i]);
    }
    solve();
    return 0;
}

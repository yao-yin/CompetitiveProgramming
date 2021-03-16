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
const int MAXN = 100010;
ll a[MAXN];
ll n, k, maxa;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(ll mid) {
    if (k == 1) {
        return mid >= maxa;
    }
    ll tot = 0;
    for (int i = 0; i < n; i ++) {
        //cout << a[i] <<" ";
        if (a[i] <= mid) continue;
        tot += (((a[i] -mid)/(k-1)) + (ll)((a[i]-mid) % (k-1) != 0));
        if(tot > mid) return false;
    }
    //cout << endl;
    //cout << mid << " " << tot << endl;
    return tot <= mid;
}

void solve() {
    ll lo = 0;
    ll hi = maxa;
    ll res = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << res << endl;
}

int main() {
    //quickread();
    scanf("%d",&n);
    for (int i = 0; i < n; i ++) {
        scanf("%lld",&a[i]);
        maxa = max(a[i], maxa);
    }
    scanf("%d",&k);
    solve();
    return 0;
}

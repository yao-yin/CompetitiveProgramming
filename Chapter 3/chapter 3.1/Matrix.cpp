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
ll T, N, M, tar;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

ll func(ll i, ll j) {
    return i*i + 100000*i + j*j - 100000*j + i*j;
}

bool check(ll i, ll j) {
    return func(i, j) <= tar;
}

ll get(int j) {
    ll lo = 1;
    ll hi = N;
    ll res = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid, j)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return res;
}

bool ccheck(ll mid) {
    tar = mid;
    ll tot = 0;
    for (int j = 1; j <= N; j ++) {
        tot += get(j);
    }
    return tot >= M;
} 

void solve() {
    ll lo = -1e12;
    ll hi = 1e12;
    ll res = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (ccheck(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << res << endl;
}

int main() {
    quickread();
    cin >> T;
    while (T --) {
        cin >> N >> M;
        solve();
    }
    return 0;
} 
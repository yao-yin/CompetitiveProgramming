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
int N, C;
ll pos[MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check (ll mid) {
    // greedy algorithm
    ll curr_pos = pos[0];
    ll tot = 1;
    for (int i = 1; i < N; i++) {
        if (pos[i] - curr_pos >= mid) {
            tot ++;
            curr_pos = pos[i];
        }
    }
    return tot >= C;
}

void solve() {
    sort(pos, pos + N);
    ll lo = 1;
    ll hi = pos[N-1] - pos[0];
    ll res = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        //cout << mid << (check(mid) ? " yes": " no") << endl;
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << endl;
}

int main() {
    quickread();
    cin >> N >> C;
    for (int i = 0; i < N; i ++) {
        cin >> pos[i];
    }
    solve();
    return 0;
}

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
const int MAXN = 50010;
ll pos[MAXN];
ll L, M, N;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(ll mid) {
    ll curr = 0;
    ll tot = 0;
    for (int i = 0; i < N; i ++) {
        if ((pos[i] - curr < mid) || (L - pos[i] < mid)) {
            //cout << curr<< "->" << pos[i] << " ";
            tot ++;
        } else {
            curr = pos[i];
        }
    }
    //cout << endl;
    //cout << "check "<< mid << " " << tot << endl;
    return tot <= M;
}
void solve() {
    sort(pos, pos + N);
    ll lo = 0;
    ll hi = L;
    ll res = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        //cout << mid << " " << (check(mid) ? "ok" : "no") << endl;
        if (check(mid)) {
            lo = mid + 1;
            res = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << endl;
}

int main() {
    quickread();
    cin >> L >> N >> M;
    for (int i = 0; i < N; i ++) {
        cin >> pos[i];
    }
    //pos[N] = L;
    solve();
    return 0;
}

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
ll money[MAXN];
ll N, M;
ll tot;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(ll mid) {
    ll curr = 0;
    ll cnt = 0;
    for (int i = 0; i < N; i ++) {
        if (money[i] > mid) {return false;}
        if (i != N-1 && curr + money[i] <= mid) {
            curr += money[i];
        } else if (i == N-1) {
            cnt += ((curr + money[i] > mid) + 1);
        } else {
            curr = money[i];
            cnt ++;
        }
    }
    return cnt <= M;
}

void solve() {
    ll lo = 0;
    ll hi = tot;
    ll res = -1;
    while (lo <= hi) {
        ll mid = (lo + hi)/2;
        if(check(mid)) {
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
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        cin >> money[i];
        tot += money[i];
    }
    solve();
    return 0;
}

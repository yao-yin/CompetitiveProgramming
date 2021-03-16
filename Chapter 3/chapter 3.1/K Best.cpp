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
typedef pair<double, double> pii;
//const double mod = 1e9+7;
int n, k;
const int MAXN = 100010;
double v[MAXN], w[MAXN];

struct Jewel {
    double v, w, x;
    int idx;
    bool operator < (const Jewel & other) const {
        return (this->v - this->w * this->x) > (other.v - other.w * other.x);
    }
}J[MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(double x) {
    for (int i = 0; i < n; i ++) J[i].x = x;
    sort(J, J + n);
    double res = 0;
    for (int i = 0; i < k; i ++) {
        res += J[i].v - J[i].w * x;
    }
    return res >= 0;
}

void solve() {
    double lo = 0;
    double hi = 1000000010;
    while (lo <= hi - 0.0000001) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    for (int i = 0; i < k; i ++) {
        if (i) cout << " ";
        cout << J[i].idx+1;
    }
    cout << endl;
}

int main() {
    quickread();
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> J[i].v >> J[i].w;
        J[i].idx = i;
    }
    solve();
    return 0;
}

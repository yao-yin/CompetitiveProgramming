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
const int MAXN = 1010;
double h[MAXN];
double A;
int N;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(double x) {
    h[2] = x;
    for (int i = 3; i <= N; i ++) {
        h[i] = (1.0 + h[i-1]) * 2.0 - h[i-2];
        if (h[i] <= 0) return false;
    }
    return true;
}

void solve() {
    double hi = A;
    h[1] = A;
    double lo = 0.0;
    double eps = 0.0000001;
    double res = -1;
    while (lo < hi - eps) {
        double mid = (lo + hi) / 2.0;
        if (check(mid)) {
            res = h[N];
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << setprecision(2) << fixed <<res << endl;
}

int main() {
    quickread();
    cin >> N >> A;
    solve();
    return 0;
}
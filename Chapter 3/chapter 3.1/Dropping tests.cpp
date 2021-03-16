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
double a[MAXN], b[MAXN];
int n, k;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void init() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
}

bool cmp(const double & a, const double & b) {
    return a > b;
}

bool check(double x) {
    vector<double> all;
    for (int i = 0; i < n; i ++) {
        all.push_back(a[i] - x*b[i]);
    }
    sort(all.begin(), all.end(), cmp);
    double res = 0;
    for (int i = 0; i < n-k; i ++) res += all[i];
    return res >= 0;
}

void solve() {
    double lo = 0;
    double hi = 1000000010;
    double res = 0;
    while (lo < hi - 0.000001) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            res = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }
    printf("%.0f\n",res*100);
}

int main() {
    quickread();
    while (cin >> n >> k, n || k) {
        init();
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i ++) {
            cin >> b[i];
        }
        solve();
    }
    return 0;
}

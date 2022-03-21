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
int n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

struct Rect {
    int coverage, area;
    Rect(int coverage, int area): coverage(coverage), area(area) {

    } 
    void add(int idx) {
        coverage |= (1 << idx);
    }
};

bool check(vector<int> &x, vector<int> &y, int i, int j, int k) {
    return ((x[k] - x[i]) * (x[k] - x[j]) <= 0) && ((y[k] - y[i]) * (y[k] - y[j]) <= 0);
}

void solve() {
    vector<int> x(n, 0), y(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i];
    }
    vector<Rect> rects;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            int coverage = (1 << i) | (1 << j);
            int area = max(1, abs(x[i] -x[j]))*max(1, abs(y[i] - y[j]));
            Rect r(coverage, area);
            for (int k = 0; k < n; k ++) {
                // try to add it
                if (k == i || k == j) continue;
                if (check(x, y, i, j, k)) {
                    r.add(k);
                }
            }
            rects.push_back(r);
        }
    }
    vector<int> dp((1 << n), 0x3f3f3f3f);
    dp[0] = 0;

    for (int i = 0; i < rects.size(); i ++) {
        
        for (int st = 0; st < (1 << n); st ++) {
            int nxt = (st | rects[i].coverage);
            dp[nxt] = min(dp[nxt], dp[st] + rects[i].area);
        }

    }
    cout << dp[(1 << n) - 1] << endl;
}

int main() {
    quickread();
    while (cin >> n, n) {
        solve();
    }
    return 0;
}

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
const int N = 1010;
int n, m, r;
ll dp[N];
struct Interval {
    int st, ed, eff;
    Interval(){}
    Interval(int s, int e, int ef, int bias) {
        st = s;
        ed = e + bias;
        eff = ef;
    }
    bool operator< (const Interval & other) const {
        return ed < other.ed;
    }
} times[N];

int find(int time, int num) {
    int l = 0;
    int r = num;
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (times[mid].ed <= time) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> n >> m >> r;
    int st,ed,eff;
    for (int i = 0; i < m; i ++) {
        cin >> st >> ed >> eff;
        times[i] = Interval(st, ed, eff, r);
    }
    sort(times, times + m);
    dp[0] = times[0].eff;
    for (int i = 1; i < m; i ++) {
        int idx = find(times[i].st, m);
        ll curr = times[i].eff;
        if (idx != -1) curr += dp[idx];
        dp[i] = max(dp[i-1], curr);
    }
    cout << dp[m-1] << endl;
    return 0;
}

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
typedef unsigned long long ll;
typedef pair<int, int> pii;
//const int mod = 1e9+7;
ll n;

void show(vector<pii> & v) {
    for (int i = 0; i < v.size(); i ++) {
        int l = v[i].first + 1;
        int r = v[i].second;
        cout << r - l + 1;
        for (int j = l; j <= r; j ++) {
            cout<< " " << j ;
        }
        cout << endl;
    }
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    ll l = 1;
    ll tot = 0;
    int cnt = 0;
    vector<pii> v;
    for (ll r = 1; r*r <= n; r ++) {
        tot += r*r;
        while (tot > n) {
            tot -= l*l;
            l ++;
        }
        if (tot == n) {
            cnt ++;
            v.push_back(make_pair(l-1, r));
        }
    }
    cout << cnt << endl;
    show(v);
}

int main() {
    quickread();
    while(cin >> n) {
        solve();
    }
    return 0;
}

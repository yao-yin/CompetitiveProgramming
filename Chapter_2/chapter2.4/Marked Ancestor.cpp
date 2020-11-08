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
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int mod = 1e9+7;
ll n, q;
const int MAXN = 1e5 + 10;
int mark[MAXN];
int par[MAXN];
int a[MAXN];
string op[MAXN];

class DSU {
public:
    vector<int> p, r;
    void init(int n) {
        p.resize(n + 10);
        r.resize(n + 10);
        for (int i = 0; i <= n; i++) {
            p[i] = i;
            r[i] = 0;
        }
    }

    int find(int x) {
        if (x == p[x]) {
            return x;
        } else {
            return p[x] = find(p[x]);
        }
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }


        p[x] = y;//new
        return true;// new

        if (r[x] < r[y]) {
            p[x] = y;
        } else {
            p[y] = x;
            if (r[x] == r[y]) {
                r[x]++;
            }
        }
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    quickread();
    DSU dsu;
    par[1] = 1;
    while (cin >> n >> q, n || q) {
        memset(mark, 0, sizeof mark);
        dsu.init(n);
        for (int i = 2; i <= n; i ++) {
            int x;
            cin >> x;
            par[i] = x;
        }
        for (int i = 1; i <= q; i ++) {
            cin >> op[i] >> a[i];
            if(op[i] == "M") mark[a[i]] ++;
        }
        for (int i = 2; i <= n; i ++) {
            if(mark[i]) continue;
            dsu.unite(i, par[i]);
        }
        ll ans = 0;
        for (int i = q; i > 0; i --) {
            if (op[i] == "M") {
                if(-- mark[a[i]]) continue;
                dsu.unite(a[i], par[a[i]]);
            } else {
                ans += dsu.find(a[i]);
            }
        } 
        cout << ans << endl;
    }
    return 0;
}

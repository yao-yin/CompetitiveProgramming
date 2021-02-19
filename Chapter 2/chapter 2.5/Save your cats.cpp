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
typedef pair<double, double> pdd;
//const int mod = 1e9+7;
const int MAXN = 10010;
const int MAXM = 50010;
pdd points[MAXN];
int par[MAXN];
int n, m, idx;

struct Edge {
    int u, v;
    double w;
    Edge(int _u, int _v, double _w) {
        this->u = _u;
        this->v = _v;
        this->w = _w;
    }
    Edge() {
        u = 0;
        v = 0;
        w = 0;
    }
    bool operator < (const Edge & other) const {
        return w > other.w;
    }
}E[MAXM];

int find(int x) {
    if (par[x] == x) {
        return x;
    } 
    int res = find(par[x]);
    par[x] = res;
    return res;
}

double Kruskal() {
    sort(E, E+m);
    double tot = 0;
    for (int i = 0; i < m; i ++) {
        int curr_from = E[i].u;
        int curr_to = E[i].v;
        double curr_w = E[i].w;
        //cout << curr_w << " " << tot << endl;
        if (find(curr_from) == find(curr_to)) continue;
        tot += curr_w;
        par[find(curr_from)] = find(curr_to);
    }
    return tot;
}

double get(int idx1, int idx2) {
    return sqrt(pow(points[idx1].first - points[idx2].first, 2) + pow(points[idx1].second - points[idx2].second, 2));
}
void init() {
    memset(E, 0, sizeof E);
    for (int i = 0; i < MAXN; i ++) par[i] = i;
    idx = 0;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> n >> m;
    init();
    double x, y;
    int p1, p2;
    for (int i = 1; i <= n; i ++) {
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }
    double tot = 0.0;
    for (int i = 0; i < m; i ++) {
        cin >> p1 >> p2;
        E[i] = Edge(p1, p2, get(p1, p2));
        tot += get(p1, p2);
        //cout << tot << endl;
    }
    cout << setprecision(5) << fixed <<tot - Kruskal() << endl;
    return 0;
}

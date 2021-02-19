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
const int MAXN = 220;
int par[MAXN];
int n, idx;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) {
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
        return w < other.w;
    }
}E[MAXN*MAXN];

int find(int x) {
    if (par[x] == x) {
        return x;
    } 
    int res = find(par[x]);
    par[x] = res;
    return res;
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

int Kruskal() {
    sort(E, E+idx);
    int tot = 0;
    for (int i = 0; i < idx; i ++) {
        int curr_from = E[i].u;
        int curr_to = E[i].v;
        int curr_w = E[i].w;
        if (find(curr_from) == find(curr_to)) continue;
        tot += curr_w;
        par[find(curr_from)] = find(curr_to);
    }
    return tot;
}

int main() {
    quickread();
    while (cin >> n) {
        init();
        int w;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cin >> w;
                E[idx ++] = Edge(i, j, w);  
            }
        }
        cout << Kruskal() << endl;
    }    
    return 0;
}

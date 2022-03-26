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
const int INF = 0x3f3f3f3f;
//const int mod = 1e9+7;
int n, m;

struct tiii {
    int dist;
    int state;
    int node;
    tiii (int x, int y, int z) : dist(x), state(y), node(z) {}
};

struct cmp {
    bool operator()(const tiii & a, const tiii & b) {
        if (a.dist > b.dist) return true;
        if (a.dist < b.dist) return false;
        if (a.state > b.state) return true;
        if (a.state < b.state) return false;
        return a.node > b.node;
    }
};

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve(vector<vector<int>> & g, vector<vector<int>> & c, vector<vector<int>> & p, vector<vector<int>> & r) {
    vector<vector<int>> dist ((1 << n), vector<int> (n, INF));
    vector<vector<bool>> st ((1 << n), vector<bool> (n, false));
    priority_queue<tiii, vector<tiii>, cmp> pq;
    pq.push(tiii(0, 1, 0));
    while (!pq.empty()) {
        tiii t = pq.top();
        int curr_dist = t.dist;
        int curr_st = t.state;
        int curr_idx = t.node;
        //cout << curr_dist << " " << curr_st << " " << curr_idx << endl;
        pq.pop();
        if (st[curr_st][curr_idx]) continue;
        st[curr_st][curr_idx] = true;
        dist[curr_st][curr_idx] = curr_dist;
        for (int i = 0; i < g[curr_idx].size(); i ++) {
            int nxt = g[curr_idx][i];
            int nxt_st = curr_st | (1 << nxt);
            int w = ((curr_st >> c[curr_idx][i]) & 1) ? p[curr_idx][i] : r[curr_idx][i];
            //cout <<"    "<< w << "  " << w + curr_dist <<" " << nxt_st << " " << nxt << endl;
            if (w + curr_dist < dist[nxt_st][nxt]) {
                pq.push(tiii(w + curr_dist, nxt_st, nxt));

            }
        }
    }
    int res = INF;
    for (int i = 0; i < (1 << n); i ++) {
        res = min(res, dist[i][n-1]);
    }
    if (res >= INF) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }
}

int main() {
    quickread();
    cin >> n >> m;
    int a, b, ci, pi, ri;
    vector<vector<int>> g(n), c(n), p(n), r(n);
    for (int i = 0; i < m; i ++) {    
        cin >> a >> b >> ci >> pi >> ri;
        a --;
        b --;
        ci --;
        g[a].push_back(b);
        c[a].push_back(ci);
        p[a].push_back(pi);
        r[a].push_back(ri); 
    }
    solve(g, c, p, r);
    return 0;
}

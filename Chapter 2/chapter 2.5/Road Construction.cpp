
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
const int MAXM = 40020;
const int MAXN = 10010;
int h[MAXN], e[MAXM], ne[MAXM], w[MAXM], co[MAXM], dist[MAXN], cost[MAXN];
int idx, n, m;
bool st[MAXN];

void init() {
    memset(h, -1, sizeof h);
    memset(e, 0, sizeof e);
    memset(ne, 0, sizeof ne);
    memset(w, 0, sizeof w);
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(cost, 0x3f3f3f3f, sizeof cost);
    memset(co, 0, sizeof co);
    cost[1] = 0;
    memset(st, 0, sizeof st);
    idx = 0;
}

void add(int a, int b, int c, int d) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    co[idx] = d;
    h[a] = idx ++;
}

void dij() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pii src = make_pair(0, 1);
    dist[1] = 0;
    pq.push(src);
    while (!pq.empty()) {
        int curr_pos = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        if(st[curr_pos]) continue;
        st[curr_pos] = true;
        for (int i = h[curr_pos]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > curr_dist + w[i]) {
                dist[j] = curr_dist + w[i];
                cost[j] = co[i]; 
                pq.push(make_pair(dist[j], j));
            } else if (dist[j] == curr_dist + w[i] && cost[j] > co[i]) {
                cost[j] = co[i]; 
                pq.push(make_pair(dist[j], j));
            }
        } 
    }
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    while (cin >> n >> m, n || m) {
        init();
        int u, v, d, c;
        for (int i = 0; i < m; i ++) {
            cin >> u >> v >> d >> c;
            add(u, v, d, c);
            add(v, u, d, c);
        }
        dij();
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            tot += cost[i];
        }
        cout << tot << endl;
    }
    
    return 0;
}

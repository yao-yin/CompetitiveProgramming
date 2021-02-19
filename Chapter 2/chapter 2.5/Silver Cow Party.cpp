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
const int M = 100010;
int n, m, x, idx, ridx;
int h[N], rh[N], e[M], re[M], w[M], rw[M], ne[M], rne[M];
bool st[M], rst[M];
int dist[N], rdist[N];

void init() {
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(rdist, 0x3f3f3f3f, sizeof rdist);
}

void add(int ca, int cb, int cc, int ch[], int ce[], int cne[], int cw[], int & cidx) {
    ce[cidx] = cb;
    cw[cidx] = cc;
    cne[cidx] = ch[ca];
    ch[ca] = cidx ++;    
}


void dij(int ch[], int ce[], int cne[], int cw[], int cdist[], bool cst[], int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    cdist[src] = 0;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_head = pq.top().second;
        //cout << "curr pos: " << curr_head <<" " << curr_dist << endl;
        pq.pop();
        if (cst[curr_head]) continue;
        cst[curr_head] = true;
        for (int i = ch[curr_head]; i != -1; i = cne[i]) {
            int j = ce[i];
            //cout << "    "<<i << " " << j << endl;
            if (cdist[j] > curr_dist + cw[i]) {
                cdist[j] = curr_dist + cw[i];
                pq.push(make_pair(cdist[j], j));
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
    init();
    cin >> n >> m >> x;
    int a, b, t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        add(a, b, t, h, e, ne, w, idx);
        add(b, a, t, rh, re, rne, rw, ridx);
    }

    dij(rh, re, rne, rw, rdist, rst, x);
    dij(h, e, ne, w, dist, st, x);
    
    int tot = 0;
    for (int i = 1; i <= n; i ++) {
        tot = max(tot, dist[i] + rdist[i]);
    }
    cout << tot << endl;
    return 0;
}

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
const int N = 50010;
const int M = 2*N;
int h[N], e[M], ne[M], price[N], idx, n, q;
int maxp[N], minp[N], up[N], down[N], parent[N];
int res[N];
bool st[N];
vector<int> tasks[N];
vector<pii> contain[N]; 

int find(int x) {
    if(x == parent[x]) return x;
    int y = parent[x];
    parent[x] = find(y);
    up[x] = max(up[x], max(maxp[y] - minp[x], up[y]));
    down[x] = max(down[x], max(maxp[x] - minp[y], down[y]));
    maxp[x] = max(maxp[x], maxp[y]);
    minp[x] = min(minp[x], minp[y]);
    return parent[x];
}

struct Query{
    int from, to, id;
    Query(int fr, int t, int iid) {
        from = fr;
        to = t;
        id = iid;
    }
    Query(){}
}queries[N];


void tarjan(int u) {
    //cout << u << endl;
    st[u] = true;
    for(int i = 0; i < contain[u].size(); i ++) {
        pii cont = contain[u][i];
        if(st[cont.first]) {
            tasks[find(cont.first)].push_back(cont.second);
        }
    }
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if(st[j]) continue;
        tarjan(j);
        parent[j] = u;
    }
    
    for(int i = 0; i < tasks[u].size(); i ++) {
        int task = tasks[u][i];
        int x = queries[task].from;
        int y = queries[task].to;
        int iid = queries[task].id;
        find(x);
        find(y);
        //cout << up[x] << " " << down[y] <<" "<< maxp[y] <<" " << minp[x] << endl;
        res[iid] = max(max(up[x], down[y]), maxp[y] - minp[x]);
    }
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void add(int u, int v) {
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx ++;
}

void init() {
    for(int i = 1; i < N; i ++) parent[i] = i;
    memset(h, -1, sizeof h);
}

int main()
{
    quickread();
    init();
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> price[i];
        maxp[i] = price[i];
        minp[i] = price[i];
    }
    int a, b;
    for(int i = 1; i < n; i ++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    cin >> q;
    for(int i = 1; i <= q; i ++) {
        cin >> a >> b;
        queries[i] = Query (a, b, i);
        contain[a].push_back(make_pair(b, i));
        contain[b].push_back(make_pair(a, i));
    }
    tarjan(1);
    for(int i = 1; i <= q; i ++) cout << res[i] << endl;
    return 0;
}

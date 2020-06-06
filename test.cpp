
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctime>
#define MAXN 52222
#define MAXM 222222
#define INF 1000000001
using namespace std;
vector<int>g[MAXN], st[MAXN], ed[MAXN], id[MAXN], ask[MAXN], pos[MAXN];
int mx[MAXN], mi[MAXN], up[MAXN], down[MAXN], vis[MAXN], fa[MAXN], ans[MAXN], price[MAXN];
int n, Q;

int find(int x) {
    if(fa[x] == x) return x;
    int y = fa[x];
    fa[x] = find(y);
    up[x] = max(up[y], mx[y] - price[x]);
    down[x] = max(down[y], price[x] - mi[y]);
    mx[x] = max(mx[x], mx[y]);
    mi[x] = min(mi[x], mi[y]);
    return fa[x];
}
void tarjan(int u) {
    vis[u] = 1;
    for(int i = 0; i < ask[u].size(); i++) {
        int v = ask[u][i];
        if(vis[v]) {
            int t = find(v);
            int z = pos[u][i];
            if(z > 0) {
                st[t].push_back(u);
                ed[t].push_back(v);
                id[t].push_back(z);
            } else {
                st[t].push_back(v);
                ed[t].push_back(u);
                id[t].push_back(-z);
            }
        }
    }
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!vis[v]) {
            tarjan(v);
            fa[v] = u;
        }
    }
    for(int i = 0; i < st[u].size(); i++) {
        int a = st[u][i];
        int b = ed[u][i];
        int t = id[u][i];
        find(a);
        find(b);
        ans[t] = max(up[a], max(down[b], mx[b] - mi[a]));
    }
}
 
int main() {
        scanf("%d", &n);
        int u, v, w;
 
        for(int i = 1; i <= n; i++) {
            scanf("%d", &w);
            mx[i] = mi[i] = w; fa[i] = i;
            price[i] = w;
        }
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
 
        }
        scanf("%d", &Q);
        for(int i = 1; i <= Q; i++) {
            scanf("%d%d", &u, &v);
            ask[u].push_back(v);
            pos[u].push_back(i);
            ask[v].push_back(u);
            pos[v].push_back(-i);
        }
        tarjan(1);
        for(int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
 
    return 0;
}
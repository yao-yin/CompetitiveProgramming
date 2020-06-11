#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int N = 5010;
const int M = 400010;
int h[N], rh[N], e[M], w[M], ne[M], idx;
int vis[N], dist[N], m, n, s, t, k;
bool st[N];
int distk[N];
void dij(int des) {
    memset(dist, 0x3f3f3f, sizeof dist);
    dist[des] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, des));
    while(!pq.empty()) {
        pii nan = pq.top();
        int dis = nan.first;
        int pos = nan.second;
        pq.pop();
        if(st[pos]) continue;
        st[pos] = true;
        for(int i = rh[pos]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[pos] + w[i]) {
                dist[j] = dist[pos] + w[i];
                pq.push(make_pair(dist[j], j));
            }
        }
    }
}

int astar(int src, int des, int k)  {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[src], src});
    if(src == des) vis[des] --;
    if(dist[src] == 0x3f3f3f) return -1;
    while(!pq.empty()) {
        pii nan = pq.top();
        int temp_dist = nan.first;
        int pos = nan.second;
        pq.pop();
        vis[pos] ++;
        int r_dist = temp_dist - dist[pos];
        if(vis[pos] == k && pos == des) return temp_dist;
        for(int i = h[pos]; i!= -1; i = ne[i]) {
            int j = e[i];
            pq.push(make_pair(r_dist + w[i] + dist[j], j));
        }
    }
    return -1;
}
void add(int* head, int a, int b, int c) {
    e[idx] = b;
    ne[idx] = head[a];
    w[idx] = c;
    head[a] = idx ++;
}

int main() {
    cin >> n >> m;
    if(m == 0) {
        cout << -1 << endl;
        return 0;
    }
    memset(dist, 0x3f3f3f, sizeof dist);
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    int a, b, c;
    for(int i = 1; i <= m; i ++) {
        cin >> a >> b >> c;
        add(h, a, b, c);
        add(h, b, a, c);
        add(rh, b, a, c);
        add(rh, a, b, c);
    }
    dij(n);
    cout << astar(1, n, 2) << endl;
    return 0;
}
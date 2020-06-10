#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
const int T = 25010;
const int R = 50010;
const int P = 50010;
const int INF = 0x3f3f3f3f;
int t, r, p, s;
int dist[T];
int id[T];
vector<int> blocks[T];
int deg[T];
bool st[T];
int h[T], e[2*R+P], ne[2*R+P], w[2*R+P], idx, block_idx;

void init() {
    memset(dist, INF, sizeof dist);
    memset(h, -1, sizeof h);
    dist[s] = 0;
}

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
    if(st[b]) {
        deg[id[b]] ++;
    }
}

void dfs(int src) {
    if(st[src])return;
    else {
        id[src] = block_idx;
        st[src] = true;
        blocks[block_idx].push_back(src);
        for(int i = h[src]; i != -1; i = ne[i]){
            int j = e[i];
            dfs(j);
        }
    }
}

void topo() {
    queue<int> bid;
    for(int i = 1; i <= block_idx; i ++) {
        if(deg[i] == 0) bid.push(i);
    }
    memset(st, 0, sizeof st);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    while(!bid.empty()) {
        int curr = bid.front();
        bid.pop();
        for(int i = 0; i < blocks[curr].size(); i ++) {
            int j = blocks[curr][i];
            pq.push({dist[j], j});
        }
        while(!pq.empty()) {
            pii cur = pq.top();
            pq.pop();
            int d = cur.first;
            int x = cur.second;
            if(st[x]) continue;
            else st[x] = true;
            //cout << d << " " << x << endl;
            for(int i = h[x]; i != -1; i = ne[i]) {
                int j = e[i];
                if(id[x] != id[j]) {
                    deg[id[j]] --;
                    if(deg[id[j]] == 0) bid.push(id[j]);
                }
                if(dist[j] > dist[x] + w[i]) {
                    dist[j] = dist[x] + w[i];
                    if(id[x] == id[j])pq.push({dist[j], j});
                }
            }
        }
    }
}

int main() {
    cin >> t >> r >> p >> s;
    init();
    int a, b, c;
    for(int i = 0; i < r; i ++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    for(int i = 1; i <= t; i ++) {
        if(!st[i]){
            block_idx ++;
            dfs(i);
        }
    }
    for(int i = 1; i <= p; i ++) {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    topo();
    
    for(int i = 1; i <= t; i ++) {
        if(dist[i] >= INF/2) cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
    }
    
    return 0;
}
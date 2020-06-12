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
const int N = 5010, R = 200010;
int n, r;
int h[N], e[R], ne[R], w[R], idx;
int dist[N];
int visCnt[N];
bool st[N];

void init() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(h, -1, sizeof h);
}

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}

void dij(int des) {
    // calculate x-n distance
    dist[des] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, des));
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        int pos = curr.second;
        int d = curr.first;
        if(st[pos]) continue;
        st[pos] = true;
        for(int i = h[pos]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dist[j] > d + w[i]) {
                dist[j] = d + w[i];
                pq.push(make_pair(dist[j], j));
            }
        }
    }
}

int heuristic(int pos) {
    // heuristic function in A* algorithm
    return dist[pos];
}

int astar(int src, int des, int k) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(heuristic(src), src));
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        int pos = curr.second;
        int curr_dist = curr.first - heuristic(pos);
        // cout << pos << " " << curr_dist << endl;
        visCnt[pos] ++;
        if(pos == des && visCnt[pos] == k) return curr_dist;
        for(int i = h[pos]; i != -1; i = ne[i]) {
            int next_pos = e[i];
            pq.push(make_pair(curr_dist + w[i] + heuristic(next_pos), next_pos));
        }
    }
    return -1;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    quickread();
    init();
    cin >> n >> r;
    int a, b, c;
    for(int i = 1; i <= r; i ++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dij(n);
    cout << astar(1, n, 2) << endl;
    return 0;
}

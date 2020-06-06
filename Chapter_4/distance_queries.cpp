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
const int N = 40010;
const int M = 2*N;
int h[N], e[M], ne[M], w[M], idx, n, m, k;
int parent[N][16], dparent[N][16];
int depth[N], rdepth[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}

void bfs() {
    memset(depth, 0x3f3f3f, sizeof depth);
    depth[0] = 0;
    depth[1] = 1;
    rdepth[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int i = h[curr]; i != -1; i = ne[i]) {
            int j = e[i];
            if(depth[j] <= depth[curr]) continue;
            else {
                depth[j] = depth[curr] + 1;
                rdepth[j] = rdepth[curr] + w[i];
                parent[j][0] = curr;
                dparent[j][0] = w[i];
                for(int ii = 1; ii <= 15; ii ++) {
                    parent[j][ii] = parent[parent[j][ii-1]][ii-1];
                    dparent[j][ii] = dparent[j][ii-1] + dparent[parent[j][ii-1]][ii-1];
                }
                q.push(j);
            }
        }
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    for(int i = 15; i >= 0; i --) {
        if(depth[parent[a][i]] >= depth[b]) a = parent[a][i];
    }
    if(a == b) return a;
    for(int i = 15; i >= 0; i --) {
        if(parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int query(int a, int b) {
    int anc = lca(a, b);
    //cout << a << " and " << b << ": " << anc << endl;
    //cout <<rdepth[a] <<" with " <<rdepth[b] << endl;
    return rdepth[a] + rdepth[b] - 2*rdepth[anc];
}

int main()
{
    quickread();
    cin >> n >> m;
    int a, b, c;
    char e;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= m; i ++) {
        cin >> a >> b >> c >> e;
        add(a, b, c);
        add(b, a, c);
    }
    bfs();
    cin >> k;
    for(int i = 0; i < k; i ++) {
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
    return 0;
}
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
//const int MOD = 1e9+7;
const int N = 40010;
const int M = 2*N;
int h[N], e[M], ne[M], idx, n, q;
int prices[N], parent[N], maxp[N], minp[N], up[N], down[N], res[N];
bool st[N];
struct Query {
    int src, des, id;
    Query(int a, int b, int c) {
        src = a;
        des = b;
        id = c;
    }
    Query(){}
}queries[N];

vector<pii> contain[N];
vector<int> tasks;

int find(int x) {
    if(x = parent[x]) return x;
    int y = parent[x];
    parent[x] = find(y);
    return parent[x];
}

void tarjan(int u) {
    st[u] = true;
    for(int i = 0; i < contain[u].size(); i ++) {
        int another = contain[u][i].first;
        int id = contain[u][i].second;
        if(st[another]) tasks[find(another)].push_back(id);
    }
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if(st[j]) continue;
        tarjan(j);
        parent[j] = u;
    }
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void init() {
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++) {
        parent[i] = i;
    }
}
int main()
{
    quickread();
    cin >> n;
    init();
    for(int i = 1; i <= n; i ++) {
        cin >> prices[i];
        maxp[i] = minp[i] = prices[i];
    }
    int a, b;
    for(int i = 1; i < n; i ++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    cin >> q;
    for(int i = 1;i <= q; i ++) {
        cin >> a >> b;
        queries[i] = Query(a, b, i);
        contain[a].push_back(make_pair(b, i));
        contain[b].push_back(make_pair(a, i));
    }
    tarjan(1);
    for(int i = 1; i <= q; i ++) cout << res[i] << endl;
    return 0;
}

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

void init() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(h, -1, sizeof h);
    dist[n] = 0;
}

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}

void dij() {
    
}

int heuristic(int pos) {
    return dist[pos];
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    quickread();
    cin >> n >> r;
    init();
    int a, b, c;
    for(int i = 1; i <= r; i ++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dij();
    cout << astar(1, n, 2) << endl;
    return 0;
}

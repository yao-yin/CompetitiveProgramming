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
const int R = 50010;
const int offset = 10005;
int n, m, r, t;
int bcnt, gcnt;
int parent[20010];

struct Edge {
    int girl, boy, d;
    Edge() {}
    Edge(int a, int b, int c) {
        girl = a;
        boy = b;
        d = c;
    }
    bool operator < (const Edge & other) const{
        return d < other.d;
    }
} edges[R];

void init() {
    memset(edges, 0, sizeof edges);
    for(int i = 0; i < 20010; i ++) {
        parent[i] = i;
    }
    bcnt = gcnt = 0;
}


inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    quickread();
    cin >> t;
    while(t --) {
        cin >> n >> m >> r;
        init();
        int a, b, d;
        for(int i = 0; i < r; i ++) {
            cin >> a >> b >> d;
            edges[i] = Edge(a, b, d);
        }
        
    }
    return 0;
}

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
typedef pair<ll, ll> pii;
//const ll mod = 1e9+7;
const int MAXR = 50010;
const int MAXN = 20010;
const int BIAS = 10005;
ll p[MAXN];
ll T, N, M, R;

ll find(ll x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

struct Edge {
    ll girl, boy, d;
    bool operator< (const Edge & other) const {
        return d < other.d;
    }
} edges[MAXR];

bool cmp(const Edge & a, const Edge & b) {
    return a.d > b.d;
}
void init() {
    //memset(edges, 0, sizeof edges);
    for(ll i = 0; i < MAXN; i ++) p[i] = i;
}


void unite(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)return ;
    p[a]=b;
}


bool same(int a,int b)
{
    return find(a)==find(b)?true:false;
}

ll minSpanTree() {
    sort(edges, edges+R, cmp);
    ll res = 0;
    for (int i = 0; i < R; i ++) {
        ll curr_boy = edges[i].boy;
        ll curr_girl = edges[i].girl;
        if (!same(curr_boy, curr_girl)) {
            res += edges[i].d;
            unite(curr_girl, curr_boy);
        }
    }
    return res;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&R);
        init();
        ll x, y, d;
        for (ll i = 0; i < R; i ++) {
            scanf("%d%d%d", &x, &y, &d);
            edges[i].girl = x;
            edges[i].boy = y + BIAS;
            edges[i].d = d;
        }
        int res = minSpanTree();
        cout << (N+M)*10000 - res << endl;
    }
    return 0;
}
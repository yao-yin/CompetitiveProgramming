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
int N, M, E;
const int MAXE = 87000;
const int MAXN = 10010;
const int INF = 0x3f3f3f3f;

ll dp[MAXE];

struct Node {
    int l, r;
    ll v;
} tree[4*MAXE];

struct I {
    int l,r;
    ll s;
    bool operator< (const I &other) const {
        // s > 0, both are ok, no matter l or r.
        if (r < other.r) return true;
        if (r > other.r) return false;
        if (l < other.l) return true;
        if (l > other.l) return false;
        return s < other.s;
    }
} is[MAXN];

void push_up(int u) {
    tree[u].v = min(tree[2*u].v, tree[2*u+1].v);
}

void build(int u, int l, int r) {
    tree[u].l = l;
    tree[u].r = r;
    if (l == r) { 
        tree[u].v = INF;
        return;
    }
    int mid = (l + r) / 2;
    build(2*u, l, mid);
    build(2*u+1, mid+1, r);
    push_up(u);
}

ll query(int u, int l, int r) {
    if (l == 0) return 0;
    if (tree[u].l >= l && tree[u].r <= r) {
        return tree[u].v;
    }
    int mid = (tree[u].l + tree[u].r) / 2;
    ll res = INF;
    if (l <= mid) {
        res = min(res, query(2*u, l, r));
    } 
    if (r > mid) {
        res = min(res, query(2*u+1, l, r));
    }
    return res;
}

void update(int u, int idx, int v) {
    if (tree[u].l == tree[u].r) {
        tree[u].v = v;
        return;
    }
    if (idx < tree[u].l || idx > tree[u].r) {
        return;
    }
    int mid = (tree[u].l + tree[u].r) / 2;
    update(2*u, idx, v);
    update(2*u+1, idx, v);
    push_up(u);
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    int l, r, s;
    for (int i = 1; i <= N; i ++) {
        cin >> l >> r >> s;
        l -= (M - 1);
        r -= (M - 1);
        is[i].l = l;
        is[i].r = r;
        is[i].s = s;
    }
    sort(is+1, is + N + 1);
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    build(1, 1, E);
    for (int i = 1; i <= N; i ++) {
        int l = is[i].l, r = is[i].r;
        dp[r] = min(dp[r], query(1, l - 1, r-1) + is[i].s);
        update(1, r, dp[r]);
    }
    if (dp[E] >= INF) {
        cout << "-1" << endl;
    } else {
        cout << dp[E] << endl;
    }
}

int main() {
    quickread();
    cin >> N >> M >> E;
    E -= (M - 1);
    solve();
    return 0;
}

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
#include <stdlib.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int mod = 1e9+7;
const int MAXN = 50007;
const int INF = 0x3f3f3f;
int N, M;

struct Node {
    int l, r, min_v;
} tree[4*MAXN];

void build(int u, int l, int r) {
    tree[u].l = l;
    tree[u].r = r;
    tree[u].min_v = INF;
    if (l == r) return;
    else {
        build(2*u, l, (l+r)/2);
        build(2*u+1, (l+r)/2+1, r);
    }
}

void push_up(int u) {
    tree[u].min_v = min(tree[2*u].min_v, tree[2*u+1].min_v);
}

void update(int u, int idx, int v) {
    if (tree[u].l == tree[u].r) {
        tree[u].min_v = v;
        return;
    }
    int mid = (tree[u].l + tree[u].r) / 2;
    if (idx <= mid) {
        update(2*u, idx, v);
    }
    if (idx > mid) {
        update(2*u+1, idx, v);
    }
    push_up(u);
}

int query(int u, int l, int r) {
    // get the min value
    if (tree[u].l >= l && tree[u].r <= r) {
        return tree[u].min_v;
    }
    int mid = (tree[u].l + tree[u].r) / 2;
    int res = INF;
    if (mid < r) {
        res = min(res, query(2*u+1, l, r));
    }
    if (mid >= l) {
        res = min(res, query(2*u, l, r));
    }
    return res;
}

int main() {
    scanf("%d %d", &N, &M);
    build(1, 1, N);
    update(1, 1, 0);
    int a, b;
    while (M --) {
        scanf("%d %d", &a, &b);
        int f = min(query(1, b, b), query(1, a, b) + 1);
        update(1, b, f);
    }
    printf("%d\n", query(1, N, N));
    return 0;
}

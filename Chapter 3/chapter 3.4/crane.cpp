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

const int MAXN = 100010;
int segs[MAXN];

struct Node {
    int l, r;
    double x, y, lazy_tag;
}tree[4*MAXN];

void push_up(Node & u, Node & l, Node & r) {
    //use node l and node r to update node u;
    u.x = l.x + r.x;
    u.y = l.y + r.y;
}

void push_up(int u) {
    push_up(tree[u], tree[2*u], tree[2*u+1]);
}

void build(int u, int l, int r) {
    tree[u].l = l, tree[u].r = r, tree[u].lazy_tag = 0;
    if (l == r) {
        tree[u].x = 0;
        tree[u].y = segs[l];
    } else {
        int mid = ((l + r) >> 1) + (l & r & 1);
        build(2*u, l, mid);
        build(2*u+1, mid+1, r);
        push_up(u);
    }
}

void rotate(int u, double angle) {
    
}

void push_down(int u) {
    // use node u to update 2 children
    if (tree[u].l == tree[u].r) {
        tree[u].lazy_tag = 0;
    } else {
        double curr_tag = tree[u].lazy_tag;
        tree[u].lazy_tag = 0;
        tree[2*u].lazy_tag += curr_tag;
        tree[2*u+1].lazy_tag += curr_tag;
        rotate(2*u, curr_tag);
        rotate(2*u+1, curr_tag);
    }
}

void update(int u, int l, int r, double angle) {
    // update range [l, r]
    if (tree[u].l >= l && tree[u].r <= r) {
        rotate(u, angle);
        tree[u].lazy_tag += angle;
    } else {
        push_down(u);
        int mid = (l + r) / 2;
        if (l > mid) {
            update(2*u+1, l, r, angle);
        } else if (r <= mid) {
            update(2*u, l, r, angle);
        } else {
            update(2*u, l, r, angle);
            update(2*u+1, l, r, angle);
        }
        push_up(u);
    }
}

Node query(int u, int l, int r) {
    if (tree[u].l == l && tree[u].r == r) {
        return tree[u];
    } else {
        push_down(u);
        int mid = (tree[u].l + tree[u].r) / 2;
        if (l > mid) {
            //rhs
            return query(2*u+1, l, r);
        } else if (r <= mid) {
            //lhs
            return query(2*u, l, r);
        } else {
            Node lhs = query(2*u, l, mid);
            Node rhs = query(2*u+1, mid+1, r);
            Node res;
            push_up(res, lhs, rhs);
            return res;
        }
    }
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    
    return 0;
}

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
const int MAXN = 50010;
int N;

struct Interval {
    int l, r;
    int c;
    bool operator < (const Interval & other) const {
        if (r < other.r) return true;
        if (r == other.r) return l < other.l;
        return false;
    }
} intervals[MAXN];

struct Node {
    int l, r;
    bool v;
    int sum;
    bool lazy_tag;
} tree[6*MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void build(int u, int l, int r) {
    tree[u].l = l;
    tree[u].r = r;
    if (l == r) return;
    int chl = 2*u;
    int chr = 2*u + 1;
    int mid = (l + r) / 2;
    build(chl, l, mid);
    build(chr, mid+1, r);
}

void push_down(int u){
    if (tree[u].l == tree[u].r) {
        tree[u].lazy_tag = false;
    } else {
        bool tag = tree[u].lazy_tag;
        if (tag == 0) return;
        tree[u].lazy_tag = 0;
        int chl = 2*u;
        int chr = 2*u + 1;
        tree[chl].lazy_tag = true;
        tree[chr].lazy_tag = true;
        tree[chl].sum = (tree[chl].r - tree[chl].l + 1);
        tree[chr].sum = (tree[chr].r - tree[chr].l + 1);
    }
}

void push_up(int u){
    int chl = 2*u, chr = 2*u + 1;
    tree[u].sum = tree[chl].sum + tree[chr].sum;
}

int query(int u, int l, int r) {
    // get sum of [l, r]
    if (u > 200001) {
        return 0;
    }
    if (l > r) return 0;
    if (tree[u].l >= l && r >= tree[u].r) {
        return tree[u].sum;
    } 
    push_down(u);
    int mid = (tree[u].l + tree[u].r) / 2;
    int res = 0;
    //cout << "mid: " <<mid << endl; 
    if (l <= mid) res += query(2*u, l, r);
    if (r > mid) res += query(2*u+1, l, r);
    return res;
}

bool check(int l, int x, int r, int v) {
    return query(1, l, x-1) + (r - x + 1) >= v;
}

int find_pos(int u, int l, int r, int v) {
    // find x, [l...x-1] = v - (r - x + 1) 
    int left = l;
    int right = r;
    int res = -1;
    while (left <= right) { 
        int mid = (left + right) / 2;
        if (check(l, mid, r, v)) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

void update(int u, int l, int r) {
    if (tree[u].l >= l && tree[u].r <= r) {
        tree[u].sum = (tree[u].r - tree[u].l + 1);
        tree[u].lazy_tag = true;
    } else {
        push_down(u);
        int mid = (tree[u].l + tree[u].r) / 2;
        int chl = 2*u, chr = 2*u + 1;
        if (l <= mid) {
            update(chl, l, r);
        }
        if (r > mid) {
            update(chr, l, r);
        }
        push_up(u);
    }
}

void process(Interval & intv) {
    if (query(1, intv.l, intv.r) >= intv.c) {
        return;
    }
    else {
        int x = find_pos(1, intv.l, intv.r, intv.c);
        update(1, x, intv.r); 
    }
} 

void solve() {
    sort(intervals, intervals+N);
    build(1, 1, 50001);
    for (int i = 0; i < N; i ++) {
        process(intervals[i]);
    }
    cout << query(1, 1, 50001) << endl;
}

int main() {
    quickread();
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> intervals[i].l >> intervals[i].r >> intervals[i].c;
        intervals[i].l ++;
        intervals[i].r ++;
    }    
    solve();
    return 0;
}

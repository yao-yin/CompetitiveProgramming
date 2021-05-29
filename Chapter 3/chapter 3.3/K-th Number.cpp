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
int N, M;
int minv, maxv;
int A[MAXN];

struct Node {
    vector<int> v;
    int l, r;
}Tree[4*MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void merge(int u, int chl, int chr) {
    // merge 2 vec => 1 vec
    int lidx = 0, ridx = 0;
    int lsz = Tree[chl].v.size();
    int rsz = Tree[chr].v.size();
    while (lidx < lsz || ridx < rsz) {
        if (lidx == lsz || (ridx < rsz &&  Tree[chr].v[ridx] < Tree[chl].v[lidx])) {
            Tree[u].v.push_back(Tree[chr].v[ridx]);
            ridx ++;
        } else if (ridx == rsz ||  (lidx < lsz && Tree[chr].v[ridx] >= Tree[chl].v[lidx])) {
            Tree[u].v.push_back(Tree[chl].v[lidx]);
            lidx ++;
        }
    }
}

void build(int u, int l, int r) {
    Tree[u].l = l;
    Tree[u].r = r;
    if (l == r) {
        Tree[u].v.push_back(A[l]);
        return;
    }
    int mid = (l + r)/2;
    build(2*u, l, mid);
    build(2*u+1, mid+1, r);
    merge(u, 2*u, 2*u+1);
}

int getCnt(int x, int u, int l, int r) {
    if (Tree[u].r < l || Tree[u].l > r) 
        return 0;
    if (Tree[u].l >= l && Tree[u].r <= r) {
        vector<int>::iterator lb = lower_bound(Tree[u].v.begin(), Tree[u].v.end(), x);
        vector<int>::iterator ub = upper_bound(Tree[u].v.begin(), Tree[u].v.end(), x);
        int part1 = lb - Tree[u].v.begin();
        int part2 = ub - lb;
        // cout << "Node: " << u << " " << x <<endl;
        // for (auto c: Tree[u].v) cout << c <<" ";
        // cout << endl;
        // cout <<"Cnt: "<< part1 << " " << part2 << endl;
        return part1 + part2; 
    } else {
        int tot = 0;
        // cout << x <<" " << u << " " << Tree[u].l << " " << Tree[u].r << endl;
        tot += getCnt(x, 2*u, l, r);
        // cout << "left: " << tot << endl;
        tot += getCnt(x, 2*u+1, l, r);
        // cout << "tot: " << tot << endl;
        return tot;
    }
}

bool check(int x, int u, int l, int r, int k) {
    // // [L...R] how many A[i] <= x, return true if tot >= k
    //cout << x << ": "<< l <<" "<< r <<": " << getCnt(x, u, l, r) << " " << k << endl;
    return getCnt(x, u, l, r) >= k;
}

int query(int u, int l, int r, int k) {
    int lo = minv, hi = maxv;
    int res = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid, u, l, r, k)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return res;
}


int main() {
    quickread();
    cin >> N >> M;
    for (int i = 1; i <= N; i ++) {
        cin >> A[i];
        minv = min(minv, A[i]);
        maxv = max(maxv, A[i]);
    }
    build(1, 1, N);
    int l, r, k;
    for (int i = 1; i <= M; i ++) {
        cin >> l >> r >> k;
        cout << query(1, l, r, k) << endl;
    }    
    return 0;
}

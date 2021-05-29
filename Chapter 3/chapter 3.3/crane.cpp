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


inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

const int MAXN = 100010;
const double PI = acos(-1.0);
double len[MAXN];
double prv[MAXN];
int N, C;

struct Node {
    double x, y, angle;
    int l, r;
    Node(double x, double y, double angle, int l, int r) {
        this->x = x;
        this->y = y;
        this->angle = angle;
        this->l = l;
        this->r = r;
    }
    Node() {}
} tree[MAXN*4];

void build(int u, int l, int r) {
    if (l > r) return;
    if (l == r) {
        tree[u] = Node(0, len[l], 0, l, r);
        return;
    }
    int chl = 2*u;
    int chr = 2*u + 1;
    int mid = (l + r) / 2;
    build(chl, l, mid);
    build(chr, mid + 1, r);
    tree[u] = Node(0, tree[chl].y + tree[chr].y, 0, l, r); 
}

void update(int idx, double ang, int u, int l, int r) {
    // [L, R]
    // cout << idx << " at pos: " << u << " " << ang/PI*180 << " " << l <<  " " << r << endl;
    if (idx < l || idx > r) return;
    if (tree[u].l == tree[u].r) return;
    int chl = 2*u;
    int chr = 2*u + 1;
    int mid = (l + r) / 2;
    update(idx, ang, chl, l, mid);
    update(idx, ang, chr, mid+1, r);
    if (idx <= mid) {
        tree[u].angle += ang;
    }
    double Co = cos(tree[u].angle), Si = sin(tree[u].angle);
    tree[u].x = tree[chl].x + Co*tree[chr].x - Si*tree[chr].y;
    tree[u].y = tree[chl].y + Si*tree[chr].x + Co*tree[chr].y;
    // cout << u << ": " << tree[u].x << " " << tree[u].y << endl;
    // cout << "left: " << tree[chl].x << " " << tree[chl].y << endl;
    // cout << "right: " << tree[chr].x << " " << tree[chr].y << endl;
}

int main() {
    quickread();
    while (cin >> N >> C) {
        for (int i = 1; i <= N; i ++) {
            cin >> len[i];
        }
        build(1, 1, N);
        for (int i = 1; i <= N; i ++) {
            prv[i] = PI;
        }
        while (C --) {
            int s, angle_360;
            cin >> s >> angle_360;
            double a = (double) angle_360/180 * PI;
            update(s, a - prv[s], 1, 1, N);
            prv[s] = a;
            cout << fixed << setprecision(2) << tree[1].x << " " << tree[1].y << endl;
        }
    }
    return 0;
}
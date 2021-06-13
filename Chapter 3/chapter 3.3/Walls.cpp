#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 200020;
int tr[maxn * 2];

int query(int x, int v = 0, int l = 0, int r = maxn - 20) {
    if(tr[v] != -2) return tr[v];
    if (l + 1 == r) return tr[v];
    int mid = (l + r) >> 1, chl = v * 2 + 1, chr = v * 2 + 2;
    if (x < mid) return query(x, chl, l, mid);
    return query(x,chr,mid, r);
}

void update(int L, int R, int val, int v = 0, int l = 0, int r = maxn - 20) {
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        tr[v] = val;
        return;
    }
    int mid = (l + r) >> 1, chl = v * 2 + 1, chr = v * 2 + 2;
    if (tr[v] != -2) {
        tr[chl] = tr[chr] = tr[v];
        tr[v] = -2;
    }
    update(L, R, val, chl, l, mid);
    update(L, R, val, chr, mid, r);   
}

int X[maxn], Y[maxn], X_inx[maxn], Y_inx[maxn],X_comp[maxn], Y_comp[maxn],
    wall_to_fly[maxn], total_for_wall[maxn],dis[maxn];
int *arr;
int wn,pn; // wall point
bool cmp(int a, int b) {
    return arr[a] < arr[b];
}
void compress(int *X, int *Comp,int *Inx, int n=pn) {
    arr = X;
    for (int i = 0; i < n; i++) Inx[i] = i;
    sort(Inx, Inx + n, cmp);
    int cnt = 0;Comp[Inx[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (X[Inx[i]] != X[Inx[i-1]]) cnt++;
        Comp[Inx[i]] = cnt;
    }
}

void scan(int *X, int *Y, int *X_comp, int i) {
    if (i < wn) {
        int i_ = i^1;
        if (X_comp[i_] >= X_comp[i]) {
            update(X_comp[i], X_comp[i_]+1,i/2);
        }
    }else {
        int q = query(X_comp[i]);
        if (q != -1) {
            int d = min(abs(Y[i] - Y[2*q]), abs(Y[i] - Y[2*q+1]));
            i-=wn;
            if (dis[i] == -1 || d < dis[i]) {
                dis[i] = d;
                wall_to_fly[i] = q;
            }
        }
    }
}

void fly(int *X, int *Y, int *X_comp, int *Inx) {
    tr[0] = -1;
    for (int i = 0; i < pn; i++) scan(X, Y, X_comp, Inx[i]);
    tr[0] = -1;
    for (int i = pn; i >= 0; i--) scan(X, Y, X_comp, Inx[i]);
}


int main() {
    memset(dis, -1, sizeof(dis));
    int n_, m_;
    scanf("%d%d", &n_, &m_);
    wn = 2 * n_;
    pn = wn + m_;
    for (int i = 0; i < pn; i++)
        scanf("%d%d", X + i, Y + i);
    compress(X, X_comp, X_inx);
    compress(Y, Y_comp, Y_inx);
    fly(X, Y, X_comp, Y_inx);
    fly(Y, X, Y_comp, X_inx);
    for (int i = 0; i < m_; i++) total_for_wall[wall_to_fly[i]]++;
    for (int i = 0; i < n_; i++) printf("%d\n", total_for_wall[i]);
}
/*
// I hate this problem because it's too long. If I have time, I will go back to solve it.
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
int N, M;
vector<int> xs, ys;

struct Seg {
    int l, r, key, idx;
    bool vis, lazy_tag;
    Seg() {
        l = r = key = idx = vis = lazy_tag = 0;
    }
};

class SegTree {
    public:
        SegTree(int n) {
            tree = vector<Seg> (4*(n+5));
            build(1, 1, n);
        }  
        void update(int u, int l, int r, int idx, int key) {

        }
        pii query(int u, int pos, int key) {

        }
    private:
    void build(int u, int l, int r) {

    }
    vector<Seg> tree;
};


struct Segx {
    int x_1, x_2, y;
    int idx;
    bool isPoint;
    Segx(int x_1, int x_2, int y, int idx, bool isP) {
        this->x_1 = x_1;
        this->x_2 = x_2;
        this->y = y;
        this->idx = idx;
        this->isPoint = isP;
    }
    bool operator< (const Segx & other) const {
        return y < other.y;
    }
};

vector<Segx> segx;

struct Segy {
    int x, y_1, y_2;
    int idx;
    bool isPoint;    
    Segy(int x, int y_1, int y_2, int idx, bool isP) {
        this->x = x;
        this->y_1 = y_1;
        this->y_2 = y_2;
        this->idx = idx;
        this->isPoint = isP;
    }
    bool operator< (const Segy & other) const {
        return x < other.x;
    }
};

vector<Segy> segy;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void updatex(int u, int l, int r, int idx) {}

int findx(int x) {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
}

void solve() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
    // part 1, sweep from down to up
    SegTree stx(xs.size());
    for (int i = 0; i < segx.size(); i ++) {
        Segx curr = segx[i];
        if (!curr.isPoint) {
            stx.update(1, findx(curr.x_1) + 1, findx(curr.x_2), curr.idx, curr.y);
        }
        else {
            pii res = stx.query(1, curr.x_1, curr.y);
            // do sth here to get res;
        }
    }
    
    SegTree sty(ys.size());
    // part 2, sweep from down to up
    for (int i = 0; i < segy.size(); i ++) {
        Segy curr = segy[i];
        if (!curr.isPoint) {
            sty.update(1, findx(curr.y_1) + 1, findx(curr.y_2), curr.idx, curr.x);
        }
        else {
            pii res = sty.query(1, curr.x, curr.y_1);
            // do sth here to get res;
        }
    }
    

}

int main() {
    quickread();
    cin >> N >> M;
    int x_1, x_2, y_1, y_2;
    for (int i = 1; i <= N; i ++) {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        xs.push_back(x_1);
        xs.push_back(x_2);
        ys.push_back(y_1);
        ys.push_back(y_2);
        if (x_1 > x_2) swap(x_1, x_2);
        if (y_1 > y_2) swap(y_1, y_2);
        if (y_1 == y_2) {
            // segx
            Segx curr(x_1, x_2, y_1, i, false);
            segx.push_back(curr);
        } else if (x_1 == x_2) {
            // segy
            Segy curr(x_1, y_1, y_2, i, false);
            segy.push_back(curr);
        }
    }
    for (int i = 1; i <= M; i ++) {
        int x, y;
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
        Segx currx(x, x, y, i, true);
        Segy curry(x, y, y, i, true);
        segx.push_back(currx);
        segy.push_back(curry);
    }
    solve();
    return 0;
} */

// src from https://dafenghh.github.io/post/c38b5f65.html, better constant than my method, get rid of TLE.

#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>

using namespace std;
typedef long long ll;
const ll maxn = 200010;
ll cnt = 200020;
ll bit[maxn];

void Maxi(int &a, int b) {
    if (b > a) a = b;
}

ll lowbit(ll x) {
    return x & -x;
}
ll sum(ll i) {
    ll res = 0;
    for (; i > 0; i -= lowbit(i)) res += bit[i];
    return res;
}
void add(ll i, ll x) {
    for (; i <= cnt; i += lowbit(i)) bit[i] += x;
}

struct P {
    int x, y;
    P(int x = 0, int y = 0):x(x), y(y) {}
}a[maxn];

bool cmpx(const P&a, const P&b){
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
bool cmpy(const P&a, const P&b){
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

int mx[maxn];
bool sc[maxn]; // scope
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].y);
    sort(a, a + n, cmpx);
    int val = 1;
    for (int i = 0; i < n; i++) {
        int temp = a[i].x;
        a[i].x = val;
        if (temp != a[i + 1].x) val++;
    }
    sort(a, a + n, cmpy);
    val = 1;
    for (int i = 0; i < n; i++) {
        int temp = a[i].y;
        a[i].y = val;
        if (temp != a[i + 1].y) val++;
    }
    for (int i = 0; i < n; i++)
        Maxi(mx[a[i].x], a[i].y);
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = a[i].x, y = a[i].y, nx = a[i + 1].x, ny = a[i + 1].y;
        if (!sc[x] && y < mx[x]) {
            sc[x] = true;
            add(x, 1);
        }
        if (y == ny && nx > x + 1) {
            ans += sum(nx - 1) - sum(x);
        }
        if (sc[x] && y == mx[x]) {
            sc[x] = false;
            add(x, -1);
        }
    }
    ans += n;
    printf("%lld\n", ans);
}

/* 
// My code, will get TLE because of constant
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
struct P {
    int x, y;
    P() {}
    P(int x, int y) {
        this->x = x;
        this->y = y;
    }
}points[2*MAXN];
int Fenwick[2*MAXN];
int left_bound[2*MAXN], right_bound[2*MAXN];
ll N;
ll tot;
vector<int> ys;
vector<int> xs;

inline int lowbit(int x) {
    return x & (-x);
}

inline void add(int idx, int num) {
    // idx start from 0;
    idx += 1;
    for (int i = idx; i <= N; i += lowbit(i)) {
        Fenwick[i] += num;
    }
}

inline int getCnt(int l, int r) {
    // idx start from 0;
    r ++;
    l ++;
    ll res = 0;
    for (int i = r; i > 0; i -= lowbit(i)) {
        res += Fenwick[i];
    }
    for (int i = l - 1; i > 0; i -= lowbit(i)) {
        res -= Fenwick[i];
    }
    return res;
}

inline int lookUpY(int num) {
    return lower_bound(ys.begin(), ys.end(), num) - ys.begin();
}

inline int lookUpX(int num) {
    return lower_bound(xs.begin(), xs.end(), num) - xs.begin();
}

bool cmpx(const P & a, const P & b) {
    if (a.x < b.x) return true;
    if (a.x == b.x) return a.y < b.y;
    return false;
}

bool cmpy(const P & a, const P & b) {
    if (a.y < b.y) return true;
    if (a.y == b.y) return a.x < b.x;
    return false;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i ++) {
        scanf("%d%d", &points[i].x, &points[i].y);
        xs.push_back(points[i].x);
        ys.push_back(points[i].y);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    vector<vector<P> > all_pts_x;
    sort(points, points+N, cmpy);
    for (int i = 0; i < N; i ++) {
        int rx = lookUpX(points[i].x);
        int ry = lookUpY(points[i].y);
        points[i] = P(rx, ry);
        if (i == 0 || ry != points[i-1].y) {
            left_bound[ry] = rx;
        }
        if (((i > 0) && ry != points[i-1].y)) {
            right_bound[points[i-1].y] = points[i-1].x;
        }
        if (i == N - 1) {
            right_bound[ry] = rx;
        }
    }

    sort(points, points+N, cmpx);
    for (int i = 0; i < N; i ++) {
        if (i == 0 || points[i].x != points[i-1].x) {
            all_pts_x.push_back(vector<P> ());
        }
        int rx = points[i].x;
        int ry = points[i].y;
        all_pts_x.back().push_back(points[i]);
    }

    // sweep line
    for (int i = 0; i < all_pts_x.size(); i ++) {
        int l = all_pts_x[i][0].y;
        int r = all_pts_x[i].back().y;
        for (int j = 0; j < all_pts_x[i].size(); j ++) {
            if (left_bound[all_pts_x[i][j].y] == all_pts_x[i][j].x) {
                add(all_pts_x[i][j].y, 1);
                //cout <<"added: " <<  all_pts_x[i][j].y << endl;
            }
        }
        //cout << l << " " << r <<" "<< getCnt(l, r) << endl; 
        tot += getCnt(l, r);
        for (int j = 0; j < all_pts_x[i].size(); j ++) {
            if (right_bound[all_pts_x[i][j].y] == all_pts_x[i][j].x) 
            add(all_pts_x[i][j].y, -1);
        }
    }
    printf("%lld\n", tot);
    return 0;
} */

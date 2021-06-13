
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
int N, Q;
int A[MAXN];
int f[MAXN][25];
int logn[MAXN];

struct Seg
{
    int l, r, v, cnt;
};

vector<Seg> segs;

void get_log() {
    logn[1] = 0;
    logn[2] = 1;
    for (int i = 3; i < MAXN; i ++) {
        logn[i] = logn[i / 2] + 1;
    }
}

pii _max(const pii & a, const pii & b) {
    if (a >= b) return a;
    return b;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void preprocess() {
    Seg curr;
    segs.clear();
    for (int i = 0; i < N; i ++) {
        if (i == 0 || A[i] != curr.v) {
            curr.l = curr.r = i;
            curr.v = A[i];
            curr.cnt = 1;
        }
        if (i == N - 1 || A[i] != A[i+1]) {
            curr.r = i;
            curr.cnt = curr.r - curr.l + 1;
            segs.push_back(curr);
            //cout << "Seg : " << endl;
            //cout << curr.v << " "<< curr.cnt << " " << curr.l << " " << curr.r << endl; 

        }
    }
    int n = segs.size();
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; i ++) f[i][0] = segs[i].cnt;
    for (int j = 1; j < 25; j ++) {
        for (int i = 0; i + (1 << j) - 1 < n; i ++) {
            f[i][j] = max(f[i][j-1], f[i + (1 << (j-1))][j-1]);
        }
    }
}

int rmq(int l, int r) {
    int s = logn[r - l + 1];
    return max(f[l][s], f[r - (1 << s) + 1][s]);
}

int get(int idx) {
    int l = 0;
    int r = segs.size() - 1;
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (segs[mid].l <= idx) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int query(int l, int r) {
    int li = get(l);
    int ri = get(r);
    //cout << li << " && " << ri << endl;
    if (li == ri) {
        //cout << "Segs [" << li << "]: " << endl;
        //cout << segs[li].v << " "<< segs[li].cnt << " " << segs[li].l << " " << segs[li].r << endl; 
        return r - l + 1;
    }    
    else if (ri > li + 1) {
        int left = segs[li].r - l + 1;
        int right = r - segs[ri].l + 1;
        int cent = rmq(li+1, ri-1);
        return max(left, max(right, cent));
    }
    else {
        int left = segs[li].r - l + 1;
        int right = r - segs[ri].l + 1;
        return max(left, right);
    }
}

void solve() {
    preprocess();
    int l, r;
    for (int i = 0; i < Q; i ++) {
        scanf("%d%d", &l, &r);
        int res = query(l-1, r-1);
        printf("%d\n", res);
    }
}

int main() {
    quickread();
    get_log();
    int idx = 0;
    while (scanf("%d", &N) != EOF && N) {
        scanf("%d", &Q);
        memset(A, 0, sizeof A);
        for (int i = 0; i < N; i ++) {
            scanf("%d", &A[i]);
        }
        solve();
    }
    return 0;
}

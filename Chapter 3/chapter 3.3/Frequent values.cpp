// https://amoshyc.github.io/ojsolution-build/poj/p3368.html
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_N = 100000;
const int MAX_LOG_N = 20;

int N, Q;
int inp[MAX_N];

int id[MAX_N];
int len[MAX_N];
int lend[MAX_N]; // [lend[i], _rend[i])
int _rend[MAX_N];

int sptb[MAX_LOG_N][MAX_N];
// sptb[i][j] = max value of [j, j + 2^i)

void sptb_init() {
    for (int i = 0; i < N; i++) {
        sptb[0][i] = len[i];
    }

    for (int i = 1; (1 << i) <= N; i++) {
        for (int j = 0; j + (1 << i) <= N; j++) {
            sptb[i][j] = max(sptb[i - 1][j], sptb[i - 1][j + (1 << (i - 1))]);
        }
    }
}

// [l, r)
int sptb_query(int l, int r) {
    int k = floor(log2(double(r - l)));
    int res1 = sptb[k][l];
    int res2 = sptb[k][r - (1 << k)];
    return max(res1, res2);
}

int main() {
    while (scanf("%d %d", &N, &Q) == 2) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &inp[i]);
        }

        // [s, t)
        int s = 0, t = 0, idx = 0;
        while (s < N) {
            while (t < N && inp[t] == inp[s]) {
                id[t++] = idx;
            }

            lend[idx] = s;
            _rend[idx] = t;
            len[idx] = t - s;

            s = t;
            idx++;
        }

        N = idx;
        sptb_init();

        while (Q--) {
            int a, b; scanf("%d %d", &a, &b); a--; b--;

            if (id[a] == id[b]) {
                printf("%d\n", b - a + 1);
                continue;
            }

            if (id[a] + 1 == id[b]) {
                int len_a = _rend[id[a]] - a;
                int len_b = b + 1 - lend[id[b]];
                printf("%d\n", max(len_a, len_b));
                continue;
            }

            int len_a = _rend[id[a]] - a;
            int len_b = b + 1 - lend[id[b]];
            int len_inner = sptb_query(id[a] + 1, id[b]);

            printf("%d\n", max(max(len_a, len_b), len_inner));
        }
    }
    return 0;
}
/* 
// 心态爆炸懒得调了，RE 但思路一样的代码
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
const int MAXN = 200010;
int N, Q;
int A[MAXN];
pii f[MAXN][25];
int logn[25];

struct Seg
{
    int l, r, v, cnt;
};

vector<Seg> segs;

void get_log() {
    logn[1] = 0;
    logn[2] = 1;
    for (int i = 3; i < 25; i ++) {
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
        }
    }
    int n = segs.size();
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; i ++) f[i][0] = make_pair(segs[i].cnt, segs[i].v);
    for (int j = 1; j < 25; j ++) {
        for (int i = 0; i + (1 << j) - 1 < n; i ++) {
            f[i][j] = _max(f[i][j-1], f[i + (1 << (j-1))][j-1]);
        }
    }
}

pii rmq(int l, int r) {
    int s = logn[r - l + 1];
    return _max(f[l][s], f[r - (1 << s) + 1][s]);
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
    if (li == ri) {
        return segs[li].cnt;
    }    
    else if (ri > li + 1) {
        pii left = make_pair(segs[li].r - l + 1, segs[li].v);
        pii right = make_pair(r - segs[ri].l + 1, segs[ri].v);
        pii cent = rmq(li+1, ri-1);
        return _max(left, _max(right, cent)).first;
    }
    else {
        pii left = make_pair(segs[li].r - l + 1, segs[li].v);
        pii right = make_pair(r - segs[ri].l + 1, segs[ri].v);
        return _max(left, right).first;
    }
}

void solve() {
    preprocess();
    int l, r;
    for (int i = 0; i < Q; i ++) {
        cin >> l >> r;
        cout << query(l-1, r-1) << endl;
    }
}

int main() {
    quickread();
    while (cin >> N, N) {
        cin >> Q;
        for (int i = 0; i < N; i ++) {
            cin >> A[i];
        }
        solve();
    }
    return 0;
} */

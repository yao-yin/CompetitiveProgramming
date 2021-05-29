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
ll A[MAXN], diff[MAXN], BIT[MAXN], BITI[MAXN], N, Q;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

inline int lowbit(int x) {
    return x & (-x);
}

void init() {
    for (int i = 1; i <= N; i ++) {
        BIT[i] += diff[i];
        int j = i + lowbit(i);
        if (j <= N) BIT[j] += BIT[i];
    }
    for (int i = 1; i <= N; i ++) {
        BITI[i] += i*diff[i];
        int j = i + lowbit(i);
        if (j <= N) BITI[j] += BITI[i];
    }
}

void add(int k, ll v) {
    ll v1 = k*v;
    while (k <= N) {
        BIT[k] += v;
        BITI[k] += v1;
        k += lowbit(k);
    }
}

void add(int l, int r, ll v) {
    add(l, v);
    add(r+1, -v);
}

ll getsum(int r) {
    ll ret = 0;
    for (int idx = r; idx > 0; idx -= lowbit(idx)) {
        ret += BIT[idx];
    }
    ret *= (r+1);
    for (int idx = r; idx > 0; idx -= lowbit(idx)) {
        ret -= BITI[idx];
    }
    return ret;
}

ll getsum(int l, int r) {
    return getsum(r) - getsum(l-1);
}

int main() {
    quickread();
    cin >> N >> Q;
    for (int i = 1; i <= N; i ++) {
        cin >> A[i];
        diff[i] = A[i] - A[i-1];
    }
    init();
    char op;
    int a, b, c;
    while (Q --) {
        cin >> op;
        if (op == 'C') {
            cin >> a >> b >> c;
            add(a, b, c);
        } else {
            cin >> a >> b;
            cout << getsum(a, b) << endl;
        }
    }
    return 0;
}

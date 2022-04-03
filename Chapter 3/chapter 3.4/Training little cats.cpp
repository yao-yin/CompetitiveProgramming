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
ll n, M, k;
const int MAXN = 101;
ll v[MAXN];

struct Matrix {
    ll data[MAXN][MAXN];
    Matrix() {
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= n; j ++) {
                data[i][j] = (i == j) ? 1 : 0;
            }
        }
    }

    void g(int i) {
        data[i][0] = 1;
    }

    void e(int i) {
        data[i][i] = 0;
    }

    void s(int i, int j) {
        data[i][i] = 0;
        data[j][j] = 0;
        data[i][j] = 1;
        data[j][i] = 1;
    }

    Matrix& operator*=(const Matrix& m) {
        ll d[MAXN][MAXN];
        memset(d, 0, sizeof(d));
        for (int i = 0; i <= n; i ++) {
            for (int k = 0; k <= n; k ++) {
                if (m.data[i][k]) { // sparse matrix
                    for (int j = 0; j <= n; j ++) {
                        d[i][j] += m.data[i][k]*data[k][j];
                    }
                }
            }
        }
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= n; j ++) {
                data[i][j] = d[i][j];
            }
        }
        return *this;
    }
};

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

Matrix power(Matrix &mat) {
    Matrix res;
    while(M) {
        if (M & 1) {
            res *= mat;
        }
        mat *= mat;
        M >>= 1;
    }
    return res;
}

void solve() {
    v[0] = 1;
    char op;
    int a, b;
    Matrix m;
    for (int i = 0; i < k; i ++) {
        cin >> op;
        if (op == 's') {
            cin >> a >> b;
        } else {
            cin >> a;
        }
        Matrix o;
        if (op == 's') {
            o.s(a, b);
        } else if (op == 'e'){
            o.e(a);
        } else {
            o.g(a);
        }
        m *= o;
    }
    Matrix mat = power(m);
    for (int i = 1; i <= n; i ++) {
        cout << mat.data[i][0] << " ";
    }
    cout << endl;
}

int main() {
    quickread();
    while (cin >> n >> M >> k, n || M || k) {
        solve();
    }
    return 0;
}

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
int T, N;
const int MOD = 10007;
struct Matrix {
    int m[4][4];
    Matrix() {
        memset(m, 0, sizeof m);
    }
};

Matrix mult(Matrix & a, Matrix & b, int mod) {
    Matrix res;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            int curr = 0;
            for (int k = 0; k < 4; k ++) {
                curr += a.m[i][k] * b.m[k][j] % mod;
            }
            res.m[i][j] = curr % mod;
        }
    }
    return res;
}

Matrix qmi(Matrix & a, int p, int mod) {
    Matrix res;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            res.m[i][j] = (i == j) ? 1 : 0;
        }
    }
    Matrix carry = a;
    while (p) {
        if (p & 1) {
            res = mult(res, carry, mod);
        }
        carry = mult(carry, carry, mod);
        p >>= 1;
    }
    return res;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void show(Matrix mat) {
    cout << "Matrix: " << endl;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            cout << mat.m[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    Matrix mat;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            if (i == j) {
                mat.m[i][j] = 2;
            } else if (i + j == 3) {
                mat.m[i][j] = 0;
            } else {
                mat.m[i][j] = 1;
            }
        }
    }
    Matrix res = qmi(mat, N, 10007);
    //show(res);
    int ret = res.m[3][3];
    cout << ret << endl;
}

int main() {
    quickread();
    cin >> T;
    for (int i = 0; i < T; i ++) {
        cin >> N;
        solve();
    }
    return 0;
}

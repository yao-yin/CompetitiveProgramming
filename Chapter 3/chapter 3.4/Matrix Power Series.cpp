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
typedef pair<ll, ll> pii;
//const ll mod = 1e9+7;
const ll MAXN = 30;

struct Matrix {
    ll m[MAXN][MAXN];
    Matrix(ll v) {
        for (ll i = 0; i < MAXN; i ++) { 
            for (ll j = 0; j < MAXN; j ++) {
                m[i][j] = (i == j) ? v : 0;
            }
        }
    }
};

Matrix mult(Matrix a, Matrix b, ll mod, ll n) {
    Matrix res(0);
    for (ll k = 0; k < n; k ++) {
        for (ll i = 0; i < n; i ++) {
            ll r = a.m[i][k];
            for (ll j = 0; j < n; j ++) {
                res.m[i][j] += r*b.m[k][j];
                res.m[i][j] %= mod;
            }
            
        }
    }
    return res;
}

Matrix add(Matrix a, Matrix b, ll mod, ll n) {
    Matrix res(0);
    for (ll i = 0; i < n; i ++) {
        for (ll j = 0; j < n; j ++) {
            res.m[i][j] = (a.m[i][j] + b.m[i][j]) % mod;
        }
    }
    return res;
}

Matrix qmi(Matrix b, ll p, ll mod, ll n) {
    Matrix res(1);
    Matrix a = b;
    while (p) {
        if (p & 1) {
            res = mult(res, a, mod, n);
        }
        a = mult(a, a, mod, n);
        p >>= 1;
    }
    return res;
}

Matrix psum(const Matrix & a, ll p, ll mod, ll n) {
    // calculate sum(a, a^2.. a^p)
    if (p == 1) {
        return a;
    }
    if (p == 0) {
        return Matrix(1);
    }
    Matrix ind(1);
    Matrix last_part = mult(psum(a, p >> 1, mod, n), add(ind, qmi(a, p >> 1, mod, n), mod, n), mod, n);
    if (p & 1) {
        return add(last_part, qmi(a, p, mod, n), mod, n);
    }
    return last_part;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    ll n, k, m;
    cin >> n >> k >> m;
    Matrix a(0);
    for (ll i = 0; i < n; i ++) {
        for (ll j = 0; j < n; j ++) {
            cin >> a.m[i][j];
        }
    }
    Matrix res = psum(a, k, m, n);
    for (ll i = 0; i < n; i ++) {
        for (ll j = 0; j < n; j ++) {
            cout << res.m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

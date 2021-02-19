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
int Z, M, H;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

ll _pow(ll a, ll b, ll mod) {
    if(b == 0) return 1 % mod;
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}
int main() {
    quickread();
    ll a, b;
    cin >> Z;
    while (Z --) {
        cin >> M >> H;
        ll res = 0;
        for (int i = 0; i < H; i ++) {
            cin >> a >> b;
            res += _pow(a, b, M);
            res %= M;
        }
        cout << res << endl;
    }
    return 0;
}

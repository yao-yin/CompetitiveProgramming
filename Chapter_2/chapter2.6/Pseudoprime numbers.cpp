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

ll _pow(ll a, ll p) {
    //return a^p mod p
    ll mod = p;
    ll res = 1;
    while (p) {
        if (p&1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        p >>= 1;
    }
    return res;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool isPrime(ll p) {
    for (ll i = 2; i*i <= p; i ++) {
        if (p % i == 0) return false;
    }
    return true;
}
int main() {
    quickread();
    ll p, a;
    while (cin >> p >> a, p||a) {
        if(isPrime(p)) {
            cout << "no" <<endl;
            continue;
        } else {
            cout << (_pow(a, p) == a ? "yes" :"no") << endl; 
        }
    }
    return 0;
}

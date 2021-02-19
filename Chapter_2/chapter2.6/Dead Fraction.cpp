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
typedef pair<ll, ll> pii;
//const ll mod = 1e9+7;


inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

ll qmi(ll a, ll b) {
    if (b == 0) return 1; 
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
    
}

ll gcd (ll a, ll b) {
    return b == 0 ? a: gcd(b, a % b);
}

string parse(string & frac) {
    return frac.substr(2, frac.size()-3-2);
}

ll _stoi(const string & curr) {
    ll res = 0;
    for (ll i = 0; i < curr.size(); i ++) {
        res *= 10;
        res += curr[i] - '0';
    }
    return res;
}
pii solve(string & dddd) {
    ll max_denominator = 0x3f3f3f3f;
    ll curr_x = 0, curr_y = 0;
    for (ll A = 0; A < dddd.size(); A ++) {
        ll B = dddd.size() - A;
        ll partA = A == 0 ? 0 : _stoi(dddd.substr(0, A));
        ll tot = _stoi(dddd);
        //cout << tot << " & " << partA << endl;
        ll new_denominator = qmi(10, A+B) - qmi(10, A);
        ll new_nominator = tot - partA;
        ll GCD = gcd(new_nominator, new_denominator);
        //cout << new_nominator << " " << new_denominator << endl;
        ll tmp_x = new_nominator / GCD;
        ll tmp_y = new_denominator / GCD;
        if (tmp_y < max_denominator) {
            max_denominator = tmp_y;
            curr_x = tmp_x;
            curr_y = tmp_y;
        }
    }
    return make_pair(curr_x, curr_y);
}

int main() {
    quickread();
    string frac;
    while (cin >> frac, frac != "0") {
        string dddd = parse(frac);
        pii res = solve(dddd);
        cout << res.first << "/" << res.second << endl;
    }
    return 0;
}

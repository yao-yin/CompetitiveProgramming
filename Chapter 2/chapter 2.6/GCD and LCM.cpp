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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}


ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    ll a, b;
    while (cin >> a >> b) {
        cout << gcd(a, b) << " " <<lcm(a, b) << endl;
    }
    return 0;
}

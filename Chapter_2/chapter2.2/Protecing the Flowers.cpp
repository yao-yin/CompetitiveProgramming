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
const int N = 100010;
ll res;
ll curr_t;
struct Cow {
    ll t,d;
    Cow(ll time, ll des) {
        t = time;
        d = des;
    }
    Cow(){}
    bool operator<(const Cow & other) {
        return ((double)d / (double)t) >= ((double)other.d / (double)other.t);
    }
}cows[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    ll n;
    cin >> n;
    ll d,t;
    for(int i = 0; i < n; i ++) {
        cin >> t >> d;
        cows[i] = Cow(t, d);
    }
    sort(cows, cows + n);
    for(int i = 0; i < n; i ++) {
        res += curr_t*cows[i].d;
        curr_t += 2*cows[i].t;
    }
    cout << res << endl;
    return 0;
}
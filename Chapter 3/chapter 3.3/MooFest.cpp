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
//const int mod = 1e9+7;
const int MAXN = 20010;
pii p[MAXN];
ll A[MAXN], BIT[MAXN], N;

ll lowbit(ll x) {
    return x & (-x);
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> N;
    ll v, x;
    for (int i = 1; i <= N; i ++) {
        cin >> v >> x;
        p[i] = make_pair(v, x);
    }
    sort(p+1, p+1+N);
    ll tot = 0;
    for (int i = 1; i <= N; i ++) {
        
    }
    return 0;
}

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
const int N = 2010;
char q[N];
int n;
int ptrl, ptrr;
unordered_map<int, int> um;
string res;
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(int l, int r) {
    int code = l*n + r;
    if(um.count(code)) return um[code];
    int ret;
    if(q[l] < q[r] || l >= r) ret = 1;
    else if(q[l] > q[r]) ret = 0;
    else ret = check(l+1, r-1);
    um[code] = ret;
    return ret;
}

void solve() {
    int l = 0;
    int r = n - 1;
    while(r >= l) {
        if(check(l, r)) {
            res += q[l ++];
        } else {
            res += q[r --];
        }
    }
}

void output() {
    int len = res.size();
    for(int i = 1; i <= len; i ++) {
        cout << res[i-1];
        if(i % 80 == 0) cout << endl;
    }
}

int main() {
    quickread();
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> q[i];
    solve();
    output();
    return 0;
}

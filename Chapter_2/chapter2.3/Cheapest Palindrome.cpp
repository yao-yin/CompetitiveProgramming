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
const int N = 2020;
bool st[N][N];
ll res[N][N];
ll del[26];
ll add[26];
int n, m;
string str;
ll query (int l, int r) {
    if(st[l][r]) {
        return res[l][r];
    } else {
        if (l >= r) {
            st[l][r] = true;
            res[l][r] = 0;
            return 0;
        } else {
            ll r1 = query(l, r-1);
            ll r2 = query(l+1, r);
            ll r3 = query(l+1, r-1);
            int left = str[l] - 'a';
            int right = str[r]- 'a';
            r1 = min(r1 + del[right], r1 + add[right]);
            r2 = min(r2 + del[left], r2 + add[left]);
            if(left != right) r3 = min(r3 + del[left] + del[right], r3 + add[left] + add[right]);
            ll ret = min(r1, min(r2, r3));
            res[l][r] = ret;
            st[l][r] = true;
            return ret;
        }
    }
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> n >> m;
    cin >> str;
    memset(add, 0x3f3f3f3f, sizeof add);
    memset(del, 0x3f3f3f3f, sizeof del);
    memset(res, 0x3f3f3f3f, sizeof res);
    char c;
    int x, y;
    for (int i = 1; i <= n; i ++) {
        cin >> c >> x >> y;
        add[c-'a'] = x;
        del[c-'a'] = y;
    }
    cout << query(0, m-1) << endl;
    return 0;
}

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
const int N = 25010;
ll n, t;
struct Seg {
    ll l, r;
    bool operator< (const Seg & other) const {
        return l < other.l;
    }
}segs[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    quickread();
    cin >> n >> t;
    ll st = 1;
    for(int i = 0; i < n; i ++) {
        cin >> segs[i].l >> segs[i].r;
    }
    sort(segs, segs + n);
    ll last = 0;
    int pos = 0;
    ll cnt = 0;
    while(last < t) {
        int curr = last + 1;
        for(int i = pos; i < n; i ++) {
            if(segs[i].l <= curr) {
                last = max(last, segs[i].r);
            } else {
                pos = i;
                break;
            }
        }
        if(curr > last) {
            cout << -1 << endl;
            break;
        }
        else {
            cnt ++;
        }
    }
    if(last >= t) cout << cnt << endl;
    return 0;
}
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
ll A[MAXN], BIT[MAXN], BIT2[MAXN], N;

ll lowbit(ll x) {
    return x & (-x);
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

ll getCnt(int idx) {
    ll tot = 0;
    for (int x = idx; x; x -= lowbit(x)) {
        tot += BIT2[x];
    }
    return tot;
}

ll getSum(int idx) {
    ll tot = 0;
    for (int x = idx; x; x -= lowbit(x)) {
        tot += BIT[x];
    }
    return tot;
}

void add(int idx, ll num) {
    // cout << "add called: " << idx << " " << N << endl; 
    for (int x = idx; x <= 20000; x += lowbit(x)) {
        BIT[x] += num;
        BIT2[x] += 1;
       // cout << x <<" => " << num << endl;
    }
}

int main() {
    quickread();
    cin >> N;
    ll v, x;
    for (int i = 1; i <= 20000; i ++) {
        cin >> v >> x;
        p[i] = make_pair(v, x);
    }
    sort(p+1, p+1+N);
    ll tot = 0;
    for (int i = 1; i <= N; i ++) {
        ll cv = p[i].first;
        ll cx = p[i].second;
        ll left_sum = getSum(cx);
        ll right_sum = getSum(20000) - left_sum;
        ll left_cnt = getCnt(cx);
        ll right_cnt = getCnt(20000) - left_cnt;
        tot += cv*(left_cnt*cx - left_sum);
        tot += cv*(right_sum - right_cnt*cx);
        //cout << i << " " << cv << " "<< cx << endl;
        //cout << left_cnt << " " << left_sum << " "  << " ? " << right_cnt  << " "<< right_sum << endl;
        //cout << tot << endl;
        add(cx, cx); 
    }
    cout << tot << endl;
    return 0;
}

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
const int MAXN = 1e5 + 10;
int X[MAXN], N, M;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(int mid) {
    int tot = 0;
    for (int i = 0; i < N-1; i ++) {
        tot += upper_bound(X + i + 1, X + N, X[i] + mid) - (X+i+1); 
        //cout << curr + mid << " "<<i <<": "<< less_ptr - (X + i)<<" " << less_ptr - X << endl;
        //int* greater_ptr = lower_bound(X, X + N, curr + mid);
        //tot += greater_ptr - X;

    }
    
    //cout << mid << " " << tot <<endl;
    return tot >= M;
}

void solve() {
    int lo = 0;
    int hi = X[N-1] - X[0];
    int res = -1;
    while (lo <= hi) {
        //int mid = (lo >> 1) + (hi >> 1) + (lo & hi & 1);
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", res);
}

int main() {
    quickread();
    while (scanf("%d", &N)!= EOF) {
        //memset(X, 0, sizeof X);
        for (int i = 0; i < N; i ++) {
            scanf("%d", &X[i]);
        }
        sort(X, X + N);
        M = (N*(N-1)/2 + 1)/2;
        solve();
        //check(8);
    }
    return 0;
}

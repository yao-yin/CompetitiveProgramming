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
const int MAXN = 4010;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN], N;
int AB[MAXN*MAXN],CD[MAXN*MAXN];
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j ++) {
            CD[i*N+j] = C[i] + D[j];
        }   
    }
    sort(CD, CD+ N*N);
    int tot = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            int cd = -(A[i] + B[j]);
            tot += upper_bound(CD, CD + N*N, cd) - lower_bound(CD, CD + N*N, cd);
        }
    }
    cout << tot << endl;
}

int main() {
    quickread();
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> A[i] >> B[i] >>C[i] >> D[i];
    }
    solve();
    return 0;
}

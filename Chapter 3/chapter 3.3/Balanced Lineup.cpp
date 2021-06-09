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
const int MAXN = 50010;
int N, Q;
int h[MAXN];
int stmin[MAXN][20];
int stmax[MAXN][20];
int logn[MAXN];

void init() {
    for (int i = 1; i <= N; i ++) {
        stmax[i][0] = stmin[i][0] = h[i];
    }
    for (int j = 1; j < 20; j ++) {
        for (int i = 1; i + (1 << j) - 1 <= N; i ++) {
            // st[i][j] => rmq(i, i + (1 << j) - 1)
            stmax[i][j] = max(stmax[i][j-1], stmax[i+(1 << (j-1))][j-1]); 
        }
    }

    for (int j = 1; j < 20; j ++) {
        for (int i = 1; i + (1 << j) - 1 <= N; i ++) {
            // st[i][j] => rmq(i, i + (1 << j) - 1)
            stmin[i][j] = min(stmin[i][j-1], stmin[i+(1 << (j-1))][j-1]); 
        }
    }
    logn[1] = 0;
    logn[2] = 1;
    for (int i = 3; i <= N; i ++) {
        logn[i] = logn[i/2] + 1;
    }

}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int rmaxq(int l, int r) {
    int s = logn[r-l+1];
    return max(stmax[l][s], stmax[r - (1 << s) + 1][s]);
}

int rminq(int l, int r) {
    int s = logn[r-l+1];
    return min(stmin[l][s], stmin[r - (1 << s) + 1][s]);
}

int main() {
    //quickread();
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &h[i]);
    }
    init();
    int l, r;
    for (int i = 1; i <= Q; i ++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", rmaxq(l, r) - rminq(l, r));
    }
    return 0;
}

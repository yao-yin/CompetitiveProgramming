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
const int MAXN = 500010;
char *names[MAXN][12];
int v[MAXN];
int bit[MAXN];
int N, K;
int divider[MAXN];
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int lowbit(int x) {
    return x & (-x);
}

int hightbit(int x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x - ((unsigned)x >> 1);
}

void dividerPreprocess() {
    for (int i = 1; i < MAXN; i ++) {
        divider[i] += 1;
        for (int j = 2; j*i < MAXN; j ++) {
            divider[i*j] += 1;
        }
    }
}

void build() {
    memset(bit, 0, sizeof bit);
    for (int i = 1; i <= N; i ++) {
        bit[i] += 1;
        int j = i + lowbit(i);
        if (j <= N) bit[j] += bit[i];
    }
}

int getSum(int idx) {
    int tot = 0;
    for (int i = idx; i > 0; i -= lowbit(i)) {
        tot += bit[i];
    }
    return tot;
}

int find(int x) {
    // getSum(u) = x, return u
    int pos = 0;
    int sum = 0;
    for (int hi = hightbit(N); hi > 0; hi >>= 1) {
        if (pos + hi < N && sum + bit[pos + hi] < x) {
            sum += bit[pos + hi];
            pos += hi;
        }
    }
    return pos + 1;
}

void add(int idx, int val) {
    for (int i = idx; i <= N; i += lowbit(i)) {
        bit[i] += val;
    }
}

int calPreSum(int idx, int currSum) {
    int val = v[idx];
    if (val >= 0) {
        // go left from idx
        int left = getSum(idx);
        int right = currSum - left;
        val %= currSum;
        return ((left - 1 + currSum + val) % currSum) + 1;
    } else {
        // go right from idx
        int left = getSum(idx);
        int right = currSum - left;
        val = -val;
        val %= currSum;
        int ret = (left + currSum - val) % currSum;
        return ret + 1;
    }
}

void solve() {
    int curr = K;
    int resIdx = 0;
    int num = 0;
    for (int i = 1; i <= N; i ++) {
        int idx = find(curr);
        //printf("%d %d %s\n", i, idx, names[idx]);
        if (divider[i] > num) {
            resIdx = idx;
            num = divider[i];
        }
        add(idx, -1);
        if (i != N) {
            curr = calPreSum(idx, N-i);
            //printf("%d currSum: %d\n", curr, N-i);
        }
    }
    printf("%s %d\n", names[resIdx], num);
}

int main() {
    //quickread();
    dividerPreprocess();
    while (scanf("%d%d", &N, &K) != EOF) {
        for (int i = 1; i <= N; i ++) {
            scanf("%s%d", names[i], &v[i]);
        }
        build();
        solve();
    }
    return 0;
}

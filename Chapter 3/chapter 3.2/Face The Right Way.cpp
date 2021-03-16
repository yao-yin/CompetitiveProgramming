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
const int MAXN = 5010;
int value[MAXN];
int diff[MAXN];
int curr[MAXN];
int K, M, N;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void add(int i, int j, int num, int* d) {
    d[i-1] += num;
    d[j+1] -= num;
}

int check(int k) {
    int cnt = 0;
    int init = 0;
    memcpy(curr, diff, sizeof(curr));
    for (int i = 1; i + k - 1 <= N; i ++) {
        init += curr[i];
        if ((init & 1)) continue;

        init ++;
        curr[i] ++;
        curr[i+k] --;
        cnt ++;
    }
    int valid = 0;
    for (int i = 0; i <= N; i ++) {
        
        valid += curr[i];
        //cout << curr[i] << " " <<valid << endl;
        if(i > 0 && ((valid & 1) == 0)) return MAXN;
    }
    //cout << endl;
    //cout << k << cnt << endl;
    return cnt;
}

void solve() {
    int tot = MAXN;
    int K;
    for (int k = 1; k <= N; k ++) {
        int res = check(k);
        //cout << k << " " << res << endl;
        if (res < tot) {
            tot = res;
            K = k;
        }
    }
    cout << K << " " << tot << endl;
}

int main() {
    quickread();
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        char c;
        cin >> c;
        value[i] = (c == 'F');
        diff[i] = value[i] - value[i-1];
    }
    /*for (int i = 1; i <= N; i ++) {
        cout << diff[i] << " ";
    }
    cout << endl;*/
    //check(2);
    solve();
    return 0;
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
const int MAXN = 10010;
int n;
bool isPrime[MAXN];
vector<int> primes;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void init_primes() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = false;
    isPrime[0] = false;
    for (int i = 2; i < MAXN; i ++) {
        if (!isPrime[i]) continue;
        primes.push_back(i);
        for (int j = 2; j * i < MAXN; j ++) {
            isPrime[i*j] = false;
        }
    }
}

void solve() {
    int l = 0;
    int tot = 0;
    int cnt = 0;
    for (int r = 0; r < primes.size(); r ++) {
        tot += primes[r];
        while (tot > n) {
            tot -= primes[l++];
        }
        if (tot == n) cnt ++;
    }
    cout << cnt << endl;
}

int main() {
    quickread();
    init_primes();
    while (cin >> n, n) {
        solve();
    }
    return 0;
}

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int mod = 1e9+7;
const int MAXN = 1000010;
bool isPrime[MAXN];
int sum[MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void init() {
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i < MAXN; i ++) {
        if (!isPrime[i]) continue;
        for (int j = 2; j*i < MAXN; j ++) {
            isPrime[j*i] = 0;
        }
    }
    for (int i = 1; i < MAXN; i ++) {
        sum[i] = (int) isPrime[i] + sum[i-1];
    }
}

int main() {
    quickread();
    init();
    int n;
    while(cin >> n) {
        cout << sum[n] << endl;
    }
    return 0;
}

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
//const ll mod = 1e9+7;
const ll MAXN = 1000010;
bool isHPrime[MAXN];
bool isHSemiPrime[MAXN];
ll sum[MAXN];
vector<ll> HPrimes;
vector<ll> semiHPrimes;
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void init() {
    memset(isHPrime, 1, sizeof isHPrime);
    for (ll i = 1; 4*i + 1 < MAXN; i ++) {
        if(!isHPrime[4*i+1]) {
            continue;
        } else {
            HPrimes.push_back(4*i+1);
            for(ll j = 1; 4*j+1 < MAXN && (4*i+1)*(4*j+1) < MAXN; j ++) {
                isHPrime[(4*i+1)*(4*j+1)] = false;
            }
        }
    }
    for (ll i = 0; i < HPrimes.size(); i ++) {
        for (ll j = 0; j < HPrimes.size() && HPrimes[i]*HPrimes[j] < MAXN; j ++) {
            
            isHSemiPrime[HPrimes[i]*HPrimes[j]] = 1;
        }
    }
    for (ll i = 1; i < MAXN; i ++) {
        sum[i] = (isHSemiPrime[i] ? 1 : 0) +sum[i-1];
    }
}

int main() {
    quickread();
    init();
    ll num;
    while(cin >> num, num) {
        cout << num << " " << sum[num] << endl;
    }
    return 0;
}

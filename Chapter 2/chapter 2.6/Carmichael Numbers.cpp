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


inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

ll qmi(ll a, ll n) {
    // a^n % n == a
    ll res = 1;
    ll unit = a;
    ll n_copy = n;
    while (n) {
        if (n & 1) {
            res *= unit;
            res %= n_copy;
        }
        unit *= unit;
        unit %= n_copy;
        n >>= 1;
    }
    return res % n_copy;
}

bool isPrime(int x) {
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool isCarmicheal(int n) {
    if (isPrime(n)) {
        //cout << n << " is prime." << endl;
        return false;
    }
    for (int i = 2; i < n; i ++) {
        // i^n % n == i?
        if (qmi(i, n) != i) {
            return false;
        }
    }
    return true;
}

int main() {
    quickread();
    int n;
    while (cin >> n, n) {
        if (isCarmicheal(n)) {
            cout << "The number " << n <<" is a Carmichael number." <<endl;
        } else {
            cout << n << " is normal." << endl;
        }
    }   
    return 0;
}

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
const int MAXN = 1200010;
bool isPrime[MAXN];
unsigned long long fact[21];

vector<int> primes;

string _to_string(int value) {
    if (value == 0) return "0";
    string ret = "";
    while (value) { 
        ret.push_back(value % 10 + '0');
        value /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void init() {
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i < MAXN; i ++) {
        if (!isPrime[i]) {
            
            continue;
        }
        else {
            primes.push_back(i);
            for (int j = 2; i*j < MAXN; j ++) {
                isPrime[i*j] = false;
            }
        }
    }
    fact[0] = 1;
    for (int i = 1; i <= 20; i ++) {
        fact[i] = fact[i-1]*i;
    }

}

void dfs(unordered_set<string> & paths, vector<string> & path, unordered_map<string, int> & factors, int steps) {
    if (path.size() == steps) {
        string tot = "";
        for (int i = 0; i < path.size(); i ++) {
            tot += "#";
            tot += path[i];
        }
        paths.insert(tot);
    }
    for (unordered_map<string, int>::iterator iter = factors.begin(); iter != factors.end(); iter ++) {
        if(iter->second == 0) continue;
        path.push_back(iter->first);
        iter->second --;
        dfs(paths, path, factors, steps);
        iter->second ++;
        path.pop_back();
    }
}

void solve(int x) {
    unordered_map<int, int> factors;
    int steps = 0;
    
    for (int i = 0; i < primes.size() && primes[i] <= x; i ++) {
        while (x % primes[i] == 0) {
            factors[primes[i]] ++;
            steps ++;
            x /= primes[i];
        }
    }
    unsigned long long tot = fact[steps];
    for (unordered_map<int, int>::iterator iter = factors.begin(); iter != factors.end(); iter ++) {
        tot/= fact[iter->second];
    }
    cout << steps << " " << tot << endl;
}

int main() {
    quickread();
    init();
    int x;
    while (cin >> x) {
        solve(x);
    }
    return 0;
}

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
int n;
priority_queue<ll, vector<ll>, greater<ll>> pq;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

ll solve() {
    ll res = 0;
    while(pq.size() >= 2) {
        ll curr = pq.top();
        pq.pop();
        ll next = pq.top();
        pq.pop();
        res += (curr + next);
        pq.push(curr + next);
    }
    return res;
}

int main() {
    quickread();
    ll wood;
    cin >> n;
    while(n --) {
        cin >> wood;
        pq.push(wood);
    }
    cout << solve() << endl;
    return 0;
}

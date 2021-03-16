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
const int MAXN = 100010;
int num[MAXN], S, N, T;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    cin >> N >> S;
    for (int i = 0; i < N; i ++) {
        cin >> num[i];
    }
    int curr = 0;
    int left = 0;
    int res = MAXN;
    for (int right = 0; right < N; right ++) {
        curr += num[right];
        while (curr >= S) {
            res = min(res, right - left + 1);
            curr -= num[left];
            left ++;
            
        }
        //cout << left << " & " << right << endl;
    }
    
    cout << ((res == MAXN) ? 0 : res )<< endl;
}

int main() {
    quickread();
    cin >> T;
    while (T --) {
        solve();
    }
    return 0;
}
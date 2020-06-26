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
const int N = 1010;
int r, n;
int coor[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int solve() {
    int res = 0;
    sort(coor, coor + n);
    int last = coor[0] - r - 1;
    int curr;
    for(int i = 0; i < n; i ++) {
        if(coor[i] - last <= r) continue;
        else {
            curr = coor[i];
            for(int j = i; j <= n; j ++) {
                if(coor[j] - curr > r || j == n) {
                    res ++;
                    i = j - 1;
                    last = coor[j-1];
                    break;
                }
            }
        }
    }
    return res;
}

int main() {
    quickread();
    while(cin >> r >> n , r != -1 || n != -1) {
        memset(coor, 0, sizeof coor);
        for(int i = 0; i < n; i ++) cin >> coor[i];
        cout << solve() << endl;
    }
    return 0;
}

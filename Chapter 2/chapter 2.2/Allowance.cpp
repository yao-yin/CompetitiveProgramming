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
const int N = 25;
int res, n, c, used[N];
struct Coin {
    int deno, cnt;
    Coin(int a, int b) {
        deno = a;
        cnt = b;
    }
    Coin(){}
    bool operator< (const Coin & other) const {
        return deno < other.deno;
    }
}coins[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> n >> c;
    int den, ct;
    for(int i = 0; i < n; i ++) {
        cin >> den >> ct;
        coins[i] = Coin(den, ct);
    }
    sort(coins, coins + n);
    while(true) {
        memset(used, 0, sizeof used);
        int rest = c;
        for(int i = n - 1; i >= 0; i --) {
            int temp = min(coins[i].cnt, rest / coins[i].deno);
            rest -= temp * coins[i].deno;
            used[i] += temp;
        }
        if(rest) {
            for(int i = 0; i < n; i ++) {
                if(coins[i].cnt > used[i] && coins[i].deno >= rest) {
                    used[i] ++;
                    rest -= coins[i].deno;
                    break;
                }
            }
        }
        if(rest > 0) {
            break;
        }
        int minweek = 0x3f3f3f3f;
        for(int i = 0; i < n; i ++) {
            if(used[i]) {
                minweek = min(minweek, coins[i].cnt / used[i]);
            }
        }
        res += minweek;
        for(int i = 0; i < n; i ++) {
            coins[i].cnt -= minweek*used[i];
        }
    }
    cout << res << endl;
    return 0;
}
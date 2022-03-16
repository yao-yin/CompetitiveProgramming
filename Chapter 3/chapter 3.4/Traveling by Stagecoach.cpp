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
const int MAXN = 32;
const int MAXT = 10;
const double INF = 0x3f3f3f;

double g[MAXN][MAXN];
double dp[(1 << MAXT)][MAXN];
double tickets[MAXT];
int T, N, P, A, B;

void init() {
    memset(tickets, 0, sizeof(tickets));
    for (int i = 0; i < MAXN; i ++) {
        for (int j = 0; j < MAXN; j ++) {
            g[i][j] = (double) INF;
            if (i == j) g[i][j] = 0;
        }
    }
    for (int i = 0; i < (1 << MAXT); i ++) {
        for (int j = 0; j < MAXN; j ++) {
            dp[i][j] = (double) INF;
        }
    }
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}


void solve() {
    dp[0][A] = 0;
    for (int st = 1; st < (1 << T); st ++) {
        for (int des = 1; des <= N; des ++) {
            // dp[st][des] 
            for (int last = 0; last < T; last ++) {
                if ((st >> last) & 1 == 0) continue;
                for (int src = 1; src <= N; src ++) {
                    if (g[src][des] >= INF) continue;
                    dp[st][des] = min(dp[st][des], dp[st ^ (1 << last)][src] + g[src][des] / tickets[last]);
                }
            }
        }
    }
    double res = INF;
    for (int st = 0; st < (1 << T); st ++) {
        res = min(res, dp[st][B]);
    }
    if (res >= INF) {
        cout << "Impossible" << endl;
    } else {
        cout << fixed << setprecision(3) << res << endl;
    }
}

int main() {
    quickread();
    while (cin >> T >> N >> P >> A >> B, T || N || P || A || B) {
        init();
        for (int i = 0; i < T; i ++) {
            cin >> tickets[i];
        }
        for (int i = 0; i < P; i ++) {
            double curr;
            int src, des;
            cin >> src >> des >> curr;
            g[src][des] = min(g[src][des], curr);
            g[des][src] = min(g[des][src], curr);
        }
        solve();
    }
    return 0;
}

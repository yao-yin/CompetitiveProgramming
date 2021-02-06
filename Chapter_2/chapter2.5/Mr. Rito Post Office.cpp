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
const int N = 220, R = 1010;
const int INF = 0x3f3f3f3f;
int n, m, r;
int land[N][N];
int sea[N][N];
bool isHabour[N];
int order[R];
int dp[R][N];
void floyd(int g[N][N]) {
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            //cout << g[i][j] << " ";
        }
        //cout << endl;
    }
}

void init() {
    memset(land, INF, sizeof(land));
    for (int i = 0; i < N; i ++) land[i][i] = 0;
    memset(sea, INF, sizeof(sea));
    for (int i = 0; i < N; i ++) sea[i][i] = 0;
    memset(dp, INF, sizeof(dp));
    memset(isHabour, 0, sizeof isHabour);
    memset(order, 0, sizeof order);
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    floyd(land);
    floyd(sea);
    int src = order[1];
    dp[1][src] = 0;
    for (int i = 2; i <= r; i ++) {
        int curr = order[i];
        int prev = order[i-1];
        for (int j = 1; j <= n; j ++) {
            // calculate dp[i][j] from dp[i-1][k] -> dp[i][j]
            for (int k = 1; k <= n; k ++) {
                // cout << prev <<" " << k << " " << curr << " " << j ; 
                if (land[prev][curr] < INF && land[prev][k] < INF && land[curr][j] < INF) {
                    // cout << " case1" ;
                    // case 1: on the same land
                    if (j == k && land[prev][curr] < INF) {
                        // j == k
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + land[prev][curr]);
                    }
                    else {
                        // j != k
                        dp[i][j] = min(dp[i][j], dp[i-1][k] +land[prev][k]+ sea[k][j] + land[j][curr]);
                    }
                }
                //
                else if (land[prev][curr] >= INF && land[prev][k] < INF && land[curr][j] < INF) {
                    // cout << " case2 " <<" " << dp[i-1][k] << " " <<land[prev][k] <<" "<< sea[k][j] <<" "<< land[j][k];
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + land[prev][k] + sea[k][j] + land[j][curr]);
                }
                // cout << endl;
            }
            //cout << curr << " " << j << ": " << dp[i][j] << endl;
        }
    }
}


int main() {
    quickread();
    while (cin >> n >> m, n || m) {
        init();
        int x, y, t;
        char sl;
        for (int i = 0; i < m; i ++) {
            cin >> x >> y >> t >> sl;
            if (sl == 'L') {
                land[x][y] = min(land[x][y], t);
                land[y][x] = land[x][y];
            } else if (sl == 'S') {
                sea[x][y] = min(sea[x][y], t);
                sea[y][x] = sea[x][y];
                isHabour[x] = true;
                isHabour[y] = true;
            }
        }
        cin >> r;
        for (int i = 1; i <= r; i ++) {
            cin >> order[i];
        }
        solve();
        int tot = INF;
        for (int i = 1; i <= n; i ++) {
            tot = min(tot, dp[r][i]);
        }
        cout << tot << endl;
    } 
    return 0;
}

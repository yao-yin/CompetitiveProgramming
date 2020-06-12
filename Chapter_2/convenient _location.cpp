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
const int N = 12;
int g[N][N], n, m;
int total[N];
void floyd(){
    for(int k = 0; k <= n; k ++) {
        for(int i = 0; i <= n; i ++) {
            for(int j = 0; j <= n; j ++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

void init() {
    memset(g, 0x3f3f, sizeof g);
    memset(total, 0x3f3f, sizeof total);
    for(int i = 0; i < N; i ++) g[i][i] = 0;
    n = 0;
}

void getres() {
    int curr_tot = 0x3f3f3f;
    int pos = -1;
    for(int i = 0; i <= n; i ++) {
        int tot = 0;
        for(int j = 0; j <= n; j ++) {
            tot += g[i][j];
        }
        total[i] = tot;
    }
    for(int i = 0; i <= n; i ++) {
        if(curr_tot > total[i]) {
            curr_tot = total[i];
            pos = i;
        } 
    }
    cout << pos << " " << curr_tot << endl;
}
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    quickread();
    while(cin >> m, m) {
        int a, b, d;
        init();
        for(int i = 0; i < m; i ++) {
            cin >> a >> b >> d;
            n = max(n, a);
            n = max(n, b);
            g[a][b] = min(g[a][b], d);
            g[b][a] = min(g[b][a], d);
        }

        floyd();
        getres();
    }
    return 0;
}

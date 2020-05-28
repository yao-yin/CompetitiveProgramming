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
const int N = 310;
int board[N][N];
bool st[N][N];
int m, x, y, t;
int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int bfs() {
    queue<pii> q;
    if(!st[0][0]) return 0;
}
int main()
{
    quickread();
    memset(board, 0x3f3f3f, sizeof board);
    cin >> m;
    for(int i = 0; i < m; i ++) {
        cin >> x >> y >> t;
        board[x][y] = min(board[x][y], t);
        st[x][y] = true;
        for(int j = 0; j < 4; j ++) {
            int newx = x + dirx[i];
            int newy = y + diry[i];
            if(newx >= 0 && newy >= 0) {
                board[newx][newy] = min(board[newx][newy], t);
                st[newx][newy] = true;
            }
        }
    }
    cout << bfs() << endl;
    return 0;
}

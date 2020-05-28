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
int dist[N][N];

int m, x, y, t;
int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int bfs() {
    queue<pii> q;
    q.push(make_pair(0, 0));
    dist[0][0] = 0;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        if(!st[x][y]) {
            cout << x << " " << y << endl;
            return dist[x][y];
        }
        for(int i = 0; i < 4; i ++) {
            int newx = x + dirx[i];
            int newy = y + diry[i];
            if(newx < 0 || newy < 0 || dist[newx][newy] <= dist[x][y] + 1 ||board[newx][newy] <= dist[x][y] + 1) continue;
            dist[newx][newy] = dist[x][y] + 1;
            q.push(make_pair(newx, newy));
        }
    }
    return -1;
}
int main()
{
    quickread();
    memset(board, 0x3f3f3f, sizeof board);
    memset(dist, 0x3f3f3f, sizeof dist);
    cin >> m;
    for(int i = 0; i < m; i ++) {
        cin >> x >> y >> t;
        cout <<x << " " << y << " " << t << endl;
        board[x][y] = min(board[x][y], t);
        st[x][y] = true;
        for(int j = 0; j < 4; j ++) {
            int newx = x + dirx[i];
            int newy = y + diry[i];
            if(newx >= 0 && newy >= 0) {
                cout << newx << " " << newy 
                board[newx][newy] = min(board[newx][newy], t);
                st[newx][newy] = true;
            }
        }
    }
    cout << bfs() << endl;
    return 0;
}

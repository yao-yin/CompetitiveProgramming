//https://vjudge.net/problem/Aizu-0118
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
const int N = 110;
char maze[N][N];
int h, w;
bool st[N][N];
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline void dfs(int x, int y, char curr) {
    if(maze[x][y] != curr) return;
    st[x][y] = true;
    for(int i = 0; i < 4 ; i ++) {
        int newx = x + dirx[i];
        int newy = y + diry[i];
        if(newx < 0 || newx >= h || newy < 0 || newy >= w || st[newx][newy]) continue;
        dfs(newx, newy, curr);
    }
}

int main()
{
    quickread();
    while(cin >> h >> w, h || w) {
        string line;
        memset(st, 0, sizeof st);
        for(int i = 0; i < h; i ++) {
            cin >> line;
            for(int j = 0; j < w; j ++) {
                maze[i][j] = line[j];
            }
        }
        int cnt = 0;
        for(int i = 0; i < h; i ++) {
            for(int j = 0; j < w; j ++) {
                if(!st[i][j]) {
                    dfs(i, j, maze[i][j]);
                    cnt ++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

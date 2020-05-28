//https://vjudge.net/problem/Aizu-0558#author=0
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
const int H = 1010;
const int W = 1010;
const int T = 11;
char board[H][W];
int dist[H][W];
int h, w, n;
int srx, sry, res;
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, -1, 0, 1};
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(int srcx, int srcy, int tar) {
    memset(dist, 0x3f3f, sizeof dist);
    queue<pii> q;
    q.push(make_pair(srcx, srcy));
    dist[srcx][srcy] = 0;
    while(!q.empty()) {
        auto curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();
        if(board[x][y] - '0' == tar) {
            srx = x;
            sry = y;
            res += dist[x][y];
            return;
        }
        for(int i = 0; i < 4; i ++) {
            int newx = x + dirx[i];
            int newy = y + diry[i];
            if(newx < 0 || newx >= h || newy < 0 || newy >= w ||board[newx][newy] == 'X' || dist[newx][newy] <= dist[x][y] + 1) continue;
            dist[newx][newy] = dist[x][y] + 1;
            q.push(make_pair(newx, newy));
        }
    }
}

int main()
{
    quickread();
    cin >> h >> w >> n;
    string line;
    for(int i = 0; i < h; i ++) {
        cin >> line;
        for(int j = 0; j < w; j ++) {
            board[i][j] = line[j];
            if(board[i][j] == 'S') {
                srx = i;
                sry = j;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        bfs(srx, sry, i);
    }
    cout << res << endl;
    return 0;
}

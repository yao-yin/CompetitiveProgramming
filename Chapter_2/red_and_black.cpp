//https://vjudge.net/problem/POJ-1979
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
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int mod = 1e9+7;
int h,w,cnt;
char maze[25][25];
bool st[25][25];
pii src;

int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, -1, 0, 1};

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void bfs() {
    queue<pii> q;
    q.push(src);
    st[src.x][src.y] = true;
    while(!q.empty()) {
        pii pos = q.front();
        int px = pos.x;
        int py = pos.y;
        q.pop();
        cnt ++;
        for(int i = 0; i < 4; i ++) {
            int npx = px + dirx[i];
            int npy = py + diry[i];
            if(npx < 0 || npx >= w || npy < 0 || npy >= h || st[npx][npy] || maze[npx][npy] == '#') continue;
            q.push(make_pair(npx, npy));
            st[npx][npy] = true;
        }
    }
}

int main()
{
    quickread();
    while(cin >> h >> w, h || w) {
        memset(st, 0, sizeof st);
        string curr;
        for(int i = 0; i < w; i ++) {
            cin >> curr;
            for(int j = 0; j < h; j ++) {
                maze[i][j] = curr[j];
                if(maze[i][j] == '@') src = make_pair(i, j);
            }
        }
        bfs();
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}

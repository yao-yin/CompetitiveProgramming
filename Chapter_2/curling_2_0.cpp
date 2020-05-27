//https://vjudge.net/problem/POJ-3009
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
const int H = 22;
const int W = 22;
int board[H][W], h, w;
int res = 0x3f3f3f3f;
int src_x, src_y, des_x, des_y;
int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};

inline void quickread() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void dfs(int pos_x, int pos_y, int step) { 
    //cout << pos_x << " " << pos_y << " " << step << " " << res << endl;
    if(pos_x == des_x && pos_y == des_y) {
        res = min(res, step);
        return;
    } else if(step > 10 || step >= res){
        return;
    } else {
        for(int i = 0; i < 4; i ++) {
            int tx = pos_x + dirx[i];
            int ty = pos_y + diry[i];
            while(tx >= 0 && tx < h && ty >= 0 && ty < w && board[tx][ty] != 1) {
                if(tx == des_x && ty == des_y) {
                    step ++;
                    res = min(res, step);
                    return;
                }
                tx += dirx[i];
                ty += diry[i];
            }
            if(tx==pos_x+dirx[i]&&ty==pos_y+diry[i] || tx < 0 || ty < 0 || tx >= h || ty >= w) continue;
            board[tx][ty] = 0;
            step ++;
            dfs(tx-dirx[i], ty-diry[i], step);
            board[tx][ty] = 1;
            step --;
        }
    }
}

void init() {
    memset(board, 0, sizeof board);
    res = 0x3f3f3f3f;
}

int main()
{
    quickread();
    while(cin >> w >> h, w || h) {
        init();
        for(int i = 0; i < h; i ++) {
            for(int j = 0; j < w; j ++) {
                cin >> board[i][j];
                if(board[i][j] == 2) {
                    //board[i][j] = 0;
                    src_x = i;
                    src_y = j;
                } else if(board[i][j] == 3) {
                    des_x = i;
                    des_y = j;
                }
            }
        }
        dfs(src_x, src_y, 0);
        if(res > 10) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
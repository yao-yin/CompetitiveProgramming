//https://vjudge.net/problem/POJ-3050
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
unordered_set<string> cache;
char maze[5][5];
int dirx[4];
int diry[4];

inline void dinit() {
    dirx[0] = 0, dirx[1] = -1, dirx[2] = 0, dirx[3] = 1;
    diry[0] = -1, diry[1] = 0, diry[2] = 1, diry[3] = 0;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void dfs(int x, int y, int idx, string & curr) {
    curr.push_back(maze[x][y]);
    if(idx == 5) {
        cache.insert(curr);
        return;
    } else {
        int nx, ny;
        for(int i = 0; i < 4; i ++) {
            nx = x + dirx[i];
            ny = y + diry[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            dfs(nx, ny, idx+1, curr);
            curr.erase(curr.size()-1);
        }
    }
}

void solve() {
    dinit();
    string res;
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 5; j ++) {
            res = "";
            dfs(i, j, 0, res);
        }
    }
    cout << cache.size() << endl;
}
int main() {
    quickread();
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 5; j ++) {
            cin >> maze[i][j];
        }
    }
    solve();
    return 0;
}

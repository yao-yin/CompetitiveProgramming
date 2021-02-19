//https://vjudge.net/problem/POJ-2386
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
const int M = 1010;
int matrix[M][M], cnt;
bool st[M][M];
int n, m;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void bfs(int i, int j) {
    queue<pii> q;
    q.push(make_pair(i, j));
    st[i][j] = true;
    while(!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        for(int u = t.x - 1; u <= t.x + 1; u ++) {
            for(int v = t.y - 1; v <= t.y + 1; v ++) {
                if(u >= 0 && u < n && v >= 0 && v <= m && st[u][v] == false) {
                    st[u][v] = true;
                    if(matrix[u][v] == 1) q.push(make_pair(u, v));
                }
            }
        }
    }
}


int main(){
    quickread();
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        string row;
        cin >> row;
        for(int j = 0; j < m; j ++) {
            if(row[j] == 'W') matrix[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(matrix[i][j] == 1 && st[i][j] == false) {
                cnt ++;
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

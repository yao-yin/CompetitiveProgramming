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
const int MAXN = 2010;
const int MAXH = 1000010;
int newx[MAXH]; //pos: newx[pos]-th x-coordinate
int newy[MAXH]; //pos: newy[pos]-th y-coordinate
int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};
int diff[MAXN][MAXN];
int sum[MAXN][MAXN];
bool st[MAXN][MAXN];
int h, w, n, x1, x2, y_1, y_2;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppii;
//const int mod = 1e9+7;
vector<int> x, y;
vector<ppii> recs;

int query(int xth, int yth) {
    if (sum[xth][yth]) {
        return (y[yth+1] - y[yth])*(x[xth+1] - x[xth]);
    }
    return 0;
}

void getSum() {
    for (int i = 0;i < x.size() - 1; i++) {
        for (int j = 0; j < y.size() - 1; j ++) {
            if (i == 0 && j == 0) {
                sum[i][j] = diff[i][j];
            } else if (i == 0 && j > 0) {
                sum[i][j] = diff[i][j] + sum[i][j-1];
            } else if (i > 0 && j == 0) {
                sum[i][j] = diff[i][j] + sum[i-1][j];
            } else {
                sum[i][j] = diff[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
    }
}

void setTrue(ppii rec) {
    int xx1 = rec.first.first;
    int xx2 = rec.first.second;
    int yy1 = rec.second.first;
    int yy2 = rec.second.second; 
    int xx1th = newx[xx1];
    int xx2th = newx[xx2] - 1;
    int yy1th = newy[yy1];
    int yy2th = newy[yy2] - 1;
    //cout << "ori: " << xx1 <<" " << yy1 <<" " << xx2 <<" " << yy2 << endl;
    //cout << "    " << xx1th <<" " << xx2th << " " << yy1th << " " << yy2th << endl; 
    diff[xx1th][yy1th] += 1;
    diff[xx2th+1][yy2th+1] += 1;
    if (xx2th >= 0) {
        diff[xx2th + 1][yy1th] -= 1;
    }
    if (yy2th >= 0) {
        diff[xx1th][yy2th+1] -= 1;
    }
}


inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void init() {
    memset(newx, 0, sizeof(newx));
    memset(newy, 0, sizeof(newy));
    memset(sum, 0, sizeof(sum));
    memset(diff, 0, sizeof(diff));
    memset(st, 0, sizeof(st));
    x.clear();
    y.clear();
    recs.clear();
    x.push_back(0);
    x.push_back(w);
    y.push_back(0);
    y.push_back(h);
}

void transform() {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    for (int i = 0; i < x.size(); i++) {
        newx[x[i]] = i;
    }
    for (int i = 0; i < y.size(); i ++) {
        newy[y[i]] = i;
    }
}

void bfs(int xx, int yy) {
    queue<pii> q;
    q.push({xx, yy});
    st[xx][yy] = true;
    //cout << "hey: " << xx << " " << yy << endl;
    while (!q.empty()) {
        pii head = q.front();
        q.pop();
        //cout << head.first << " " << head.second << endl;
        for (int i = 0; i < 4; i ++) {
            int new_x = head.first + dirx[i];
            int new_y = head.second + diry[i];
            if (new_x >= 0 && new_y >= 0 && new_x < x.size() - 1 && new_y < y.size() - 1 
            && !st[new_x][new_y] && query(new_x, new_y) == 0) {
                //cout << "    " << new_x << " " << new_y << endl;
                st[new_x][new_y] = true;
                q.push({new_x, new_y});
            }
        }
    }
}

int flood_fill() {
    int tot = 0;
    for (int i = 0; i < x.size() - 1; i++) {
        for (int j = 0; j < y.size() - 1; j ++) {
            //cout << i << " " << j << " " << query(i, j) << endl;
            if (query(i, j) == 0 && !st[i][j]) {
                tot += 1;
                bfs(i, j);
                //cout << i << " " << j << endl;
                //break;
            }
        }
    }
    return tot;
}

int main() {
    quickread();
    while (cin >> w >> h, h || w) {
        cin >> n;
        init();
        for (int i = 0; i < n; i ++) {
            cin >> x1 >> y_1 >> x2 >> y_2;
            x.push_back(x1); x.push_back(x2); 
            y.push_back(y_1); y.push_back(y_2);
            recs.push_back(make_pair(make_pair(x1, x2), make_pair(y_1, y_2)));
        }
        transform();
        for (auto & rec: recs) {
            setTrue(rec);
        }
        getSum();
        cout << flood_fill() << endl;
    }    
    return 0;
}

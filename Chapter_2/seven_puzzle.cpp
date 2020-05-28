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
unordered_map<string, int> dist;
int arr[2][4] = {0, 1, 2, 3, 4, 5, 6, 7};
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void init() {
    dist["01234567"] = 0;
    string src = "01234567";
    queue<string> q;
    q.push(src);
    while(!q.empty()) {
        string temp = q.front();
        q.pop();
        int zero;
        int di = dist[temp];
        for(int i = 0; i < 8; i ++) {
            if(temp[i] == '0') {
                zero = i;
            }
        }
        int x = zero/4;
        int y = zero % 4;
        for(int i = 0; i < 4; i ++) {
            int newx = x + dirx[i];
            int newy = y + diry[i];
            if(newx < 0 || newx >= 2 || newy < 0 || newy >= 4 ) continue;
            int newzero = newx*4+newy;
            swap(temp[zero], temp[newzero]);
            if(dist.count(temp)) {
                swap(temp[zero], temp[newzero]);
                continue;
            } else {
                dist[temp] = di + 1;
                q.push(temp);
            }
            swap(temp[zero], temp[newzero]);
        }
    }
}

string arrToString() {
    string res;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 4; j ++) {
            res += (arr[i][j] + '0');
        }
    }
    return res;
}
int main()
{
    quickread();
    init();
    while(cin >> arr[0][0] >> arr[0][1] >> arr[0][2] >> arr[0][3] >> arr[1][0] >> arr[1][1] >> arr[1][2] >> arr[1][3]) {
        cout <<dist[arrToString()] << endl;
    }
    return 0;
}

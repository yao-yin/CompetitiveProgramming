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
const int R = 10;
const int C = 10000;
int mt[R][C], r, c;
int res;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int states = (1 << r);
    for(int st = 0; st <= states; st ++) {
        int curr = 0;
        for(int j = 0; j < c; j ++) {
            int ones = 0;
            for(int i = 0; i < r; i ++) {
                //cout << i << "-" << j << ": " << mt[i][j] << endl; 
                ones += (((st >> i) & 1) ^ mt[i][j]);
            }
            //cout << j << " " << ones << endl;
            curr += max(ones, r - ones);
        }
        res = max(res, curr);
    }
    cout << res << endl;
}

int main() {
    quickread();
    while(cin >> r >> c, r || c) {
        for(int i = 0; i < r; i ++) {
            for(int j = 0; j < c; j ++) cin >> mt[i][j];
        }
        solve();
    }
    return 0;
}

//https://vjudge.net/problem/Aizu-0033#author=0
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
const int N = 10;
int balls[N];
int t;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool dfs(int u, bool side, int l, int r) {
    if(u == 10) return true;
    if(side) {
        if(balls[u] > l) {
            l = balls[u];
            return dfs(u + 1, 0, l, r) || dfs(u + 1, 1, l, r);
        } else return false;
    } else {
        if(balls[u] > r) {
            r = balls[u];
            return dfs(u + 1, 0, l, r) || dfs(u + 1, 1, l, r);
        } else return false;
    }
}

int main()
{
    quickread();
    cin >> t;
    for(int i = 1; i <= t; i ++) {
        for(int j = 0; j < 10; j ++) {
            cin >> balls[j];
        }
        if(dfs(0, 1, 0, 0) || dfs(0, 0, 0, 0)) {
            cout << "YES" << endl; 
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

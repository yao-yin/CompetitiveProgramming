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
int timestamp, n, q;
const int N = 100010;
int mark[N];
vector<int> query;
int queryMark[N];
int parent[N];
int tree[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void init() {
    timestamp = 1;
    memset(mark, 0, sizeof mark);
    query.clear();
    memset(queryMark, 0, sizeof queryMark);
    for (int i = 1; i <= n; i ++) {
        parent[i] = i;
    }
    tree[1] = 1;
}

void solve() {
    for(int i = 2; i <= n; i ++) {
        cin >> tree[i];
    }
    for(int i = 1; i <= q; i ++) {
        char op;
        int node;
        cin >> op >> node;
        if(op == 'Q') {
                
        }
    }
}

int main() {
    quickread();
    while(cin >> n >> q) {
        init();
        solve();
    }
    return 0;
}

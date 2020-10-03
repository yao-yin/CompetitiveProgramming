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
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int mod = 1e9+7;
const int N = 100010;
int n, q;
int tree[N];
int parent[N];
int st[N];

struct Op {
    int timestamp;
    int node;
    char op;
    Op(int a, int b, char c) {
        timestamp = a;
        node = b;
        op = c;
    }
    Op(){}
}ops[N];


inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
void init() {
    memset(ops, 0, sizeof ops);
    memset(tree, 0, sizeof tree);
    memset(st, 0, sizeof st);
    for (int i = 1; i <= n; i ++) parent[i] = i;
    tree[1] = 1;
    st[1] = 1;
    ops[1] = Op(1, 1, 'M');
}

int find(int x) {
    if(st[x]) {
        return x;
    } else {
        int res = find(tree[x]);
        tree[x] = res;
        return res; 
    }
}

int main() {
    quickread();
    while (cin >> n >> q, n || q) {
        init();
        for (int i = 2; i <= n; i ++) {
            cin >> tree[i];
        }
        char c;
        int node;
        for (int i = 2; i <= q + 1; i ++) {
            cin >> c >> node;
            ops[i] = Op(i, node, c);
            if(c == 'M') {
                st[node] = i;
            }
        }
        ll sum = 0;
        for (int query = q + 1; query > 1; query --) {
            int currtime = ops[query].timestamp;
            int currnode = ops[query].node;
            char currop = ops[query].op;
            if (currop == 'M') {
                st[currnode] = 0;
            } else {
                sum += find(currnode);
            }
        }
        cout << sum << endl;
    }
    return 0;
}

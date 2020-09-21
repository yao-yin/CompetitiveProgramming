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
const int N = 1010;
const int D = 20010;
int n, d;
int x[N], y[N];
bool st[N];
int parent[N];
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(int idx1, int idx2) {
    return (x[idx1] - x[idx2])*(x[idx1] - x[idx2])+(y[idx1] - y[idx2])*(y[idx1] - y[idx2]) <= d*d; 
}

int find(int idx) {
    if (parent[idx] == idx) return idx;
    int res = find(parent[idx]);
    parent[idx] = res;
    return res;
}

void unit(int idx1, int idx2) {
    parent[find(idx1)] = find(idx2);
}



int main() {
    quickread();
    cin >> n >> d;
    for (int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
        parent[i] = i;
    } 
    char op;
    int p, q;
    while (cin >> op) {
        if (op == 'O') {
            cin >> p;
            st[p] = true;
            for (int i = 1; i <= n; i ++) {
                if (st[i] && (i != p)) {
                    if (check(p, i)) {
                        //cout << p << " " << i << endl;
                        unit(p, i);
                    }
                }
            }
        } else if (op == 'S') {
            cin >> p >> q;
            //cout << p <<" "<< q << ": "<<find(p) << " "<<find(q) << endl; 
            if(st[p] && st[q] && find(p) == find(q)) {
                cout << "SUCCESS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}

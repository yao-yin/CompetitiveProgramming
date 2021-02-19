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
const int MAXN = 10010;
int dist[MAXN];
bool isPrime[MAXN];
int path[MAXN];

int _pow(int a, int b) {
    if (b == 0) return 1;
    int res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

void init() {
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i < MAXN; i ++) {
        if (!isPrime[i]) continue;
        else {
            for (int j = 2; i*j < MAXN; j ++) {
                isPrime[i*j] = false;
            }
        }
    }
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int change(int num, int digit, int tar) {
    // start from 0
    int c = tar*(int)_pow(10, digit);
    return num / (int)_pow(10, digit+1) * (int)_pow(10, digit+1) + c + num % (int)_pow(10, digit);
}

void solve(int src, int des) {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == des) { 
            cout << dist[curr] << endl;
            /*int c = curr;
            while ( c!= src) {
                cout << path[c] << "<-";
                c = path[c];
            }
            cout << endl;*/
            return; 
        } else {
            //explore next digit
            for (int i = 0; i < 4; i ++) {
                for (int j = 0; j < 10; j ++) {
                    if (i == 3 && j == 0) continue;
                    int ne = change(curr, i, j);
                    //cout << curr << " "<< i << " " << j << ": " << ne << endl;
                    if (dist[ne] < 0x3f3f3f3f || (!isPrime[ne])) {
                        continue;
                    } else {
                        dist[ne] = dist[curr] + 1;
                        q.push(ne);
                        path[ne] = curr;
                    }
                }
            }
        }

    }
    cout << "impossible" << endl;
}

int main() {
    quickread();
    init();
    int T;
    cin >> T;
    for (int i = 0; i < T; i ++) {
        int src, des;
        cin >> src >> des;
        solve(src, des);
    }
    return 0;
}

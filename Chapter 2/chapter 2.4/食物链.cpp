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
const int N = 50010;
const int K = 100010;
int parent[N];
int dist[N];
int d, x, y, n, k;
int cnt;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

pii find(int node) {
    // return {root, dist}
    if(parent[node] == node) return make_pair(node, 0);
    else {
        pii res = find(parent[node]);
        parent[node] = res.first;
        dist[node] += res.second;
        return make_pair(res.first, dist[node]);
    }
}
void merge(int a, int b, int r) {
    pii resa = find(a);
    parent[resa.first] = b;
    dist[resa.first] = r;
}



int diff(int a, int b) {
    return (a % 3 - b % 3 + 3) % 3;
}

int main() {
    quickread();
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++) parent[i] = i;
    for (int i = 0; i < k; i ++) {
        scanf("%d%d%d", &d, &x, &y);
        if(x <= 0 || y <= 0 || x > n || y > n) {
            cnt ++;
            continue;
        }
        pii resx = find(x);
        pii resy = find(y);
        if (d == 1) {
            if (resx.first == resy.first) {
                if(diff(resx.second, resy.second) != 0) cnt ++;
            } else {
                merge(x, y, (3-resx.second%3));
            }
        }
        if (d == 2) {
            if (resx.first == resy.first) {
                if(diff(resx.second, resy.second) != 1) cnt ++;
            } else {
                merge(x, y, 4-resx.second % 3);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

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
const int N = 5010;
const int R = 100010;
int h[N], e[2*R], ne[2*R], w[2*R], idx;
int dist[N], dist2[N], n, r;

void dij() {
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        int pos = curr.second;
        int d = curr.first;
        for(int i = h[pos]; i != -1; i = ne[i]) {
            int next_pos = e[i];
            int next_dist = d + w[i];
            if(dist[next_pos] >= next_dist) {
                dist2[next_pos] = dist[next_pos];
                dist[next_pos] = next_dist;
            } else if(next_dist ){
                
            }
        }
    }
}

inline void init() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(h, -1, sizeof h);
    memset(dist2, 0x3f3f3f3f,sizeof dist2);
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    quickread();
    cin >> n >> r;
    int a, b, c;
    for(int i = 0; i < r; i ++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dij;
    cout << dist2[n] << endl;
    return 0;
}

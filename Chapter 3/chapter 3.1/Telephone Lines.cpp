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
ll N, P, K;
const int MAXN = 400010;
int h[MAXN], e[MAXN], ne[MAXN], w[MAXN], idx;
int dist[MAXN];
bool st[MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void add(ll a, ll b, ll c) {
    e[idx] = b; 
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}

bool check(int x) {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        int curr_pos = curr.second;
        int curr_dist = curr.first;
        //cout << curr_pos <<" " << curr_dist << endl;
        if (st[curr_pos]) {
            continue;
        }
        st[curr_pos] = true;
        for (int i = h[curr_pos]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[curr_pos] + (w[i] <= x ? 0 : 1)) {
                dist[j] = dist[curr_pos] + (w[i] <= x ? 0 : 1);
                pq.push(make_pair(dist[j], j));
            }
        }
    }
    //cout << x << " " << dist[N] <<endl;
    return dist[N] <= K;
}

void solve() {
    int lo = 0;
    int hi = 1000010;
    int res = -1;
    while (lo <= hi) {
        int mid = (lo >> 1) + (hi >> 1) + (lo & hi & 1);
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        //break;
    }
    cout << res << endl;
}

int main() {
    quickread();
    ll a, b, l;
    memset(h, -1, sizeof h);
    cin >> N >> P >> K;
    while (P --) {
        cin >> a >> b >> l;
        add(a, b, l);
        add(b, a, l);
    }
    solve();
    return 0;
}
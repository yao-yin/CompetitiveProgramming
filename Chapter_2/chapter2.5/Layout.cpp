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
const int M = 40010;
const int N = 1010;
int dist[N];
int h[M], e[M], ne[M], w[M];
int idx;
int n, ml, md;
bool st[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}



bool dfs(int src) {
    if(src == n) return true;
    if(st[src]) return false;
    else {
        st[src] = true;
        for (int i = h[src]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dfs(j)) return true;
        }
        return false;
    }
}

bool check() {
    memset(st, 0, sizeof st);
    return dfs(1);
}

bool spfa() {
    queue<int> q;
    vector<bool> state(n+1, 1);
    vector<int> cnt(n+1, 0);
    for (int i = 0; i <= n; i ++) q.push(i);
    while(!q.empty()) {
        int curr = q.front();
        //cout << "now we at: " << curr << endl;
        q.pop();
        state[curr] = 0;
        for (int i = h[curr]; i != -1; i = ne[i]) {
            int j = e[i];
            //cout <<" " << j << endl;
            if(dist[j] > dist[curr] + w[i]) {
                dist[j] = dist[curr] + w[i];
                cnt[j] = cnt[curr] + 1;
                if(cnt[j] >= n+1) return false;
                if(!state[j]) {
                    state[j] = true;
                    q.push(j);
                }
            }
        }
        /*for(int i = 0; i <= n; i ++) {
            cout << dist[i] << " ";
        }
        cout << endl;*/
    }
    return true;
}

int main() {
    quickread();
    cin >> n >> ml >> md;
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f3f3f, sizeof(dist));
    dist[0] = 0;
    int a, b, d;
    for (int i = 0; i < ml; i++) {
        //ml part
        cin >> a >> b >> d;
        add(a, b, d);
    }
    for (int i = 1; i <= n; i ++)  {
        add(i, i-1, 0);
    }
    //need to do sth here
    bool any = check();

    for (int i = 0; i < md; i ++) {
        cin >> a >> b >> d;
        add(b, a, -d);
    }

    add(0, 1, 0);
    // run spfa/bellman-ford from src 0
    if (spfa()) {
        if(!any) {
            cout << -2 << endl;
        } else {
            cout << dist[n] << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}

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
const int MAXM = 6010;
int h[MAXM], e[MAXM], ne[MAXM], w[MAXM], idx;
int F, N, M, W; 
int cnt[MAXM], dist[MAXM];
bool st[MAXM];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
    memset(e, 0, sizeof e);
    memset(ne, 0, sizeof ne);
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0] = 0;
}

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}

bool spfa() {
    queue<int> q;
    for (int i = 0; i <= N; i ++) {
        q.push(i);
        st[i] = true;
    }
    while (!q.empty()) {
        int curr_head = q.front();
        q.pop();
        st[curr_head] = 0;
        for (int i = h[curr_head]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[curr_head] + w[i]) {
                dist[j] = dist[curr_head] + w[i];
                cnt[j] = cnt[curr_head] + 1;
                if (cnt[j] > N) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    quickread();
    
    cin >> F;
    while (F --) {
        init();
        cin >> N >> M >> W;
        int S, E, T;
        for (int i = 0; i < M; i ++) {
            cin >> S >> E >> T;
            add(S, E, T);
            add(E, S, T);
        }
        for (int i = 0; i < W; i ++) {
            cin >> S >> E >> T;
            add(S, E, -T);
        }
        for (int i = 1; i <= N; i ++) {
            add(0, i, 0);
        }
        if (spfa()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

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
const int N = 310;
int dist[N][N];
int n, m;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}



int main() {
    quickread();
    memset(dist, 0x3f3f, sizeof(dist));
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        dist[i][i] = 0; 
    }
    int a, b;
    vector<int> cows_for_single_movie;
    while(m --) {
        cin >> a;
        for (int i = 0; i < a; i ++) {
            cin >> b;
            cows_for_single_movie.push_back(b);
        }
        for (int i = 0; i < a; i ++) {
            for (int j = 0; j < a; j ++) {
                if(cows_for_single_movie[i] == cows_for_single_movie[j]) continue;
                dist[cows_for_single_movie[i]][cows_for_single_movie[j]] = 1;
                dist[cows_for_single_movie[j]][cows_for_single_movie[i]] = 1;
            }
        }
        cows_for_single_movie.clear();
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
           // cout << i << " " << j << " " << dist[i][j] << endl;
        }
    } 


    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int tot = 0x3f3f3f;
    for (int i = 1; i <= n; i ++) {
        int curr = 0;
        for (int j = 1; j <= n; j ++) {
            curr += dist[i][j];
        }
        tot = min(tot, curr);
    }
    cout << tot*100/(n-1) << endl;
    return 0;
}

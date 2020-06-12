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
int h[N], e[2*R], ne[2*R], w[2*R];
int dist[N], dist2[N];

void dij() {

}

inline void init() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(dist2, 0x3f3f3f3f,sizeof dist2);m
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    quickread();
    
    return 0;
}

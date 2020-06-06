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
const int M = 2*N;
int h[N], e[M], ne[M], price[N], idx, n, m;
int maxp[N], minp[N], up[N], down[N], parent[N];
bool st[N];
struct Query{
    int from, to, id;
}queries[N];

vector<Query> contain[N], task[N]; 

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void init() {
    for(int i = 1; i < N; i ++) parent[i] = i;
    memset(h, -1, sizeof h);
}

int main()
{
    quickread();
    init();    
    return 0;
}

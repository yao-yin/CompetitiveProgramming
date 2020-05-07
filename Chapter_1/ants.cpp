//https://vjudge.net/problem/POJ-1852
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
const int N = 1e7+10;
int t, len, n, pos[N];


inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}


int main()
{
    quickread();
    cin >> t;
    for(int i = 1; i <= t; i ++) {
        cin >> len >> n;
        for(int j = 0; j < n; j ++) {
            cin >> pos[j];
        }
        int max_time = 0;
        int min_time = 0;
        for(int j = 0; j < n; j ++) {
            min_time = max(min_time, min(pos[j], len - pos[j]));
            max_time = max(max_time, max(pos[j], len - pos[j]));
        }
        cout << min_time << " " << max_time << endl;
    }
    return 0;
}

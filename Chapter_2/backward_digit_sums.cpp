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
int n;
const int N = 11;
int nums[N];
int sums[N][N];
void cal                                                                                                                                                                                                                                                                           

int getSum() {
    int res = 0;
    for(int i = 0; i < n; i ++) {
        res += sums[n-1][i]*nums[i];
    }
    return res;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    
    return 0;
}

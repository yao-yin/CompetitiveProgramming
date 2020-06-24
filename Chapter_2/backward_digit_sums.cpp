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
int n, tar;
const int N = 11;
int nums[N];
int sums[N][N];
void cal() {
    sums[0][0] = 1;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= i; j ++) {
            sums[i+1][j] += sums[i][j];
            sums[i+1][j+1] += sums[i][j];
        }
    }
}                                                                                                                                                                                                                                                                         

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

void solve() {
    for(int i = 0; i < n; i ++) {
        nums[i] = i + 1;
    }
    cal();
    do {
        if(getSum() == tar) return;
    } while(next_permutation(nums, nums + n));
}
int main() {
    quickread();
    cin >> n >> tar;
    solve();
    for(int i = 0; i < n; i ++) {
        cout << nums[i] << " ";
    }
    
    return 0;
}

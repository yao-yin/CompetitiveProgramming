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
#include <sstream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int mod = 1e9+7;
const int N = 11;
int nums[N];
int test_case, n, diff;
string line;
const int INF = 0x3f3f3f3f;
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int stoi(string & s) {
    int ret = 0;
    int base = 10;
    for(int i = s.size() - 1; i >= 0; i --) {
        ret*=10;
        ret += (s[i] - '0');
    }
    return ret;
}

void getdiff() {
    int f = 0;
    int mid = n / 2;
    int l = 0;
    if(nums[0] == 0||nums[mid] == 0) return;
    for(int i = 0; i < mid; i ++) {
        f*= 10;
        f += nums[i];
    }
    for(int j = mid; j < n; j ++) {
        l *= 10;
        l += nums[j];
    }
    diff = min(diff, abs(f - l));
}

void solve() {
    memset(nums, 0, sizeof nums);
    stringstream inp(line);
    n = 0;
    string a;
    while(getline(inp, a, ' ')){
        nums[n ++] = stoi(a);
    }
    diff = INF;
    int n1, n2;
    if(n == 2) {
        diff = min(diff, abs(nums[0] - nums[1]));
    } else {
        do {
            getdiff();
        } while(next_permutation(nums, nums + n));
    }
    cout << diff << endl;
}


int main()
{
    quickread();
    cin >> test_case;
    cin.ignore();
    while(test_case --) {
        getline(cin, line);
        solve();
    }
    return 0;
}
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
int form[N];
int latter[N];
string line;
const int INF = 0x3f3f3f3f;
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void getdiff() {
    memset(form,0, sizeof form);
    memset(latter,0, sizeof latter);
    int f = 0;
    for(int i = 0; i < n; i ++) {
        form[i] = f*10 + nums[i];
        f = form[i];
        cout << form[i] <<" ";
    }
    int base = 1;
    for(int i = n-1 ; i > 0; i --) {
        latter[i] = latter[i+1] + base*nums[i];
        base *= 10;
    }
    for(int i = 0; i < n-1; i ++) {
        if(i > 0 && nums[0] == 0) continue;
        if(nums[i+1] == 0) continue;
        diff = min(diff, abs(form[i] - latter[i+1]));
    }
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
    getdiff();
    /*do {
        getdiff();
    } while(next_permutation(nums, nums + n));*/
    cout << diff << endl;
}


int main()
{
    quickread();
    cin >> test_case;
    while(test_case --) {
        cin.ignore();
        getline(cin, line);
        solve();
    }
    return 0;
}

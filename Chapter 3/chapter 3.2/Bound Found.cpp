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
const int MAXN = 1000010;
int num[MAXN], presum[MAXN];
pii arr[MAXN];
int n, k, tar;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void init() {
    memset(num, 0, sizeof(num));
    memset(presum, 0, sizeof(presum));
    memset(arr, 0, sizeof(arr));
}

void preprocessing() {
    for (int i = 1; i <= n; i ++) {
        presum[i] = presum[i-1] + num[i];
    }
    for (int i = 0; i <= n; i ++) {
        arr[i] = make_pair(presum[i], i);
    }
    sort(arr, arr+n+1);
}

bool valid(int l, int r) {
    return arr[r].second > arr[l].second;
}

void query(int tar) {
    int ret_l = -1, ret_r = -1, diff = 0x3f3f3f3f;
    int l = 0;
    for (int r = 1; r <= n; r ++) {
        int curr = arr[r].first - arr[l].first;
        if (diff > abs(curr - tar)) {
            ret_l = l;
            ret_r = r;
            diff = abs(curr - tar);
        }
        while ((arr[r].first - arr[l].first) >= tar && l < r) {
            curr = arr[r].first - arr[l].first;
            if (diff > abs(curr - tar)) {
                ret_l = l;
                ret_r = r;
                diff = abs(curr - tar);
            }
            l ++;
        }
        if (l < r) {
            curr = (arr[r].first - arr[l].first);
            if (diff > abs(curr - tar)) {
                ret_l = l;
                ret_r = r;
                diff = abs(curr - tar);
            }
        }
    }
    int res_l = min(arr[ret_l].second, arr[ret_r].second);
    int res_r = max(arr[ret_l].second, arr[ret_r].second);
    cout << arr[ret_r].first - arr[ret_l].first <<" " << res_l + 1 << " " << res_r << endl;
}

int main() {
    quickread();
    while (cin >> n >> k, n || k) {
        init();
        for (int i = 1; i <= n; i++) {
            cin >> num[i]; 
        }
        preprocessing();
        for (int i = 0; i < k; i ++) {
            cin >> tar;
            query(tar);
        }
    }
    return 0;
}

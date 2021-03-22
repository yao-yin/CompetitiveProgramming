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
bool st[20];
bool cpst[20];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    memcpy(cpst, st, sizeof(cpst));
    int cnt_1 = 0;
    int cnt_2 = 0;
    //case 1 filp 0
    st[0] = !st[0];
    st[1] = !st[1];
    cnt_1 ++;
    for (int i = 0; i + 2 < 20; i ++) {
        if(st[i]) {
            cnt_1 ++;
            st[i] = !st[i];
            st[i+1] = !st[i+1];
            st[i+2] = !st[i+2];
        }
    }
    if((st[18] && st[19]) == true) {
        cnt_1 ++;
    } else if(st[18] || st[19]) {
        cnt_1 = 0x3f3f3f;
    }
    memcpy(st, cpst, sizeof(st));
    //case 2 doesnot flip 1
    for (int i = 0; i + 2 < 20; i ++) {
        if(st[i]) {
            cnt_2 ++;
            st[i] = !st[i];
            st[i+1] = !st[i+1];
            st[i+2] = !st[i+2];
        }
    }
    if((st[18] && st[19]) == true) {
        cnt_2 ++;
    } else if(st[18] || st[19]) {
        cnt_2 = 0x3f3f3f;
    }
    cout << min(cnt_1, cnt_2) << endl;
}

int main() {
    quickread();
    int x;
    for (int i = 0; i < 20; i ++) {
        cin >> x;
        st[i] = x;
    }
    solve();
    return 0;
}

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
const int MAXN = 50010;
struct Cow {
    int w, s;
    bool operator < (const Cow & other) const {
        return w + s < other.w + other.s;
    }
} cows[MAXN];
int N;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> cows[i].w >> cows[i].s;
    }
    sort(cows, cows + N);
    int tot = -0x3f3f3f3f;
    int sum = 0;
    for (int i = 0; i < N; i ++) {
        int curr = sum - cows[i].s;
        tot = max(tot, curr);
        sum += cows[i].w;
    }
    cout << tot << endl;
    return 0;
}

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
const int N = 2510;
pii cow[N], lot[N];
int l,c;
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> c >> l;
    for (int i = 1; i <= c; i ++) {
        cin >> cow[i].first >> cow[i].second;
    }
    for (int i = 1; i <= l; i ++) {
        cin >> lot[i].first >> lot[i].second; 
    }
    sort(cow+1, cow+c+1);
    sort(lot+1, lot+l+1);
    priority_queue<int, vector<int>, greater<int>> pq;
    int cowIdx = 1;
    int cnt = 0;
    for (int i = 1; i <= l; i ++) {
        // consider lot i
        while (cowIdx <= c && cow[cowIdx].first <= lot[i].first) {
            pq.push(cow[cowIdx].second);
            cowIdx ++;
        }
        while (!pq.empty() && lot[i].second > 0) {
            if (pq.top() >= lot[i].first) {
                cnt ++;
                lot[i].second --;
            }
            pq.pop();
        }
    }
    cout << cnt << endl;
    return 0;
}

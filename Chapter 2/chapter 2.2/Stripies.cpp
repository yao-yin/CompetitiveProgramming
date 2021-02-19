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
const int N = 100;
double nums[N];
int n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> nums[i];
    priority_queue<double> pq;
    for(int i = 0; i < n; i ++) pq.push(nums[i]);
    while(pq.size() > 1) {
        double curr = pq.top();
        pq.pop();
        double next = pq.top();
        pq.pop();
        pq.push(2*sqrt(curr*next));
    }
    cout << fixed << setprecision(3) << pq.top() << endl;
    return 0;
}
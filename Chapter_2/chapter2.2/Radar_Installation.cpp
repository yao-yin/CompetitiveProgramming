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
const int N = 1010;
int t;
int n;
double d;
struct P {
    double x, y;
    bool operator < (const P & other) const {
        return x < other.x;
    }
}points[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

double getLen(int idx) {
    return sqrt(d*d - points[idx].y*points[idx].y);
}

int main()
{
    quickread();
    while(cin >> n >> d) {
        if(n == 0 && d == 0)break;
        memset(points, 0, sizeof points);
        bool flag = false;
        for(int i = 0; i < n; i ++) {
            cin >> points[i].x >> points[i].y;
            if(points[i].y > d) {
                flag = true;
            } 
        }
        if(flag) {
            cout << "Case " << ++t << ": " <<-1 << endl;
            continue;
        }
        sort(points, points + n);
        int curr = 0;
        int cnt = 0;
        while(curr < n) {
            double rbound = points[curr].x + getLen(curr);
            int j = curr;
            cnt ++;
            for(; j < n; j ++) {
                if(points[j].x - getLen(j) > rbound) break;
                rbound = min(rbound, points[j].x + getLen(j));
            }
            curr = j;
        }
        cout << "Case " << ++t << ": " <<cnt << endl;
    }
    return 0;
}

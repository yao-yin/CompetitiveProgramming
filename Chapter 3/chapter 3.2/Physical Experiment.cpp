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
int C, N;
double H, R, T;
const int MAXN = 110;
double res[MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}



double get_height(double h, double t) {
    //cout << h << " " << t << endl;
    double g = 10;
    double falling_time = sqrt(2*h/g);
    //cout << h << " " << t << " " << falling_time << endl;
    double remain = fmod(t,  2*falling_time);
    
    if (remain >= falling_time) {
        remain = 2*falling_time - remain;
    }
    
    return h - 0.5*g*remain*remain;
}

void solve() {
    memset(res, 0, sizeof(res));
    for (int i = 0; i < N; i ++) {
        double curr_t = T - (i);
        double curr_h = H;
        if(curr_t <= 0) {
            res[i] = curr_h;// + 2*i*R*0.01;
        } else {
            res[i] = get_height(curr_h, curr_t);// + 2*i*R*0.01;
        }
    }
    sort(res, res + N);
    for (int i = 0; i < N; i ++) cout << fixed << setprecision(2) <<res[i] + 2*i*R*0.01<< " ";
    cout << endl;
}

int main() {
    quickread();
    cin >> C;
    while (C --) {
        cin >> N >> H >> R >> T;
        solve();
    }
    return 0;
}

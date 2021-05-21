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
const int MAXN = 32010;
double l, v;
int n;
struct Ih {
    string name;
    double pos;
    char dir;
    Ih(string  _name, const double & _pos, const char & _dir) {
        this->name = _name;
        pos = _pos;
        dir = _dir;
    }
    Ih(){}
    bool operator< (const Ih & other) {
        return this->pos < other.pos;
    }
}ihs[MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    //sort(ihs, ihs + n);
    double tot_time = 0;
    int curr_idx = -1;
    for (int i = 0; i < n; i ++) {
        double ti = (ihs[i].dir == 'p' || ihs[i].dir == 'P') ? (l - ihs[i].pos)/v : ihs[i].pos/v;
        if(ti >= tot_time) {
            tot_time = ti;
            curr_idx = i;
        }
    }
    int cnt = 0;
    string res_name;
    if (ihs[curr_idx].dir == 'p' || ihs[curr_idx].dir == 'P') {
        for (int i = curr_idx; i < n; i ++) {
            cnt += (ihs[i].dir == 'n' || ihs[i].dir == 'N');
        }
        res_name = ihs[curr_idx + cnt].name;
        //cout << res_name << endl;
    } else {
        for (int i = curr_idx; i >= 0; i --) {
            cnt += (ihs[i].dir == 'p' || ihs[i].dir == 'P');
        }
        res_name = ihs[curr_idx - cnt].name;
    }
    cout << setw(13) << fixed << setprecision(2) << (int)(tot_time * 100) / 100.0 << ' ' << res_name << endl;
}

int main() {
    quickread();
    while (cin >> n, n) {
        cin >> l >> v;
        string curr_name;
        double curr_pos;
        char curr_dir;
        for (int i = 0; i < n; i ++) {
            cin >> curr_dir >> curr_pos >> curr_name;
            //cout << curr_name;
            ihs[i] = Ih(curr_name, curr_pos, curr_dir);
        }
        solve();
    }
    return 0;
}
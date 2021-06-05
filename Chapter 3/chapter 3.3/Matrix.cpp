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
const int MAXN = 1010;
int T, M, Q;

class Bit2D {
    public:
        Bit2D(int x, int y) {
            MAXX = x;
            MAXY = y;
            for (int i = 0; i < MAXN; i ++) {
                for (int j = 0; j < MAXN; j ++) {
                    bit[i][j] = 0;
                }
            }
        }

        void add2D(int _x1, int _y1, int _x2, int _y2, int v) {
            add(_x1, _y1, v);
            add(_x1, _y2+1, -v);
            add(_x2+1, _y1, -v);
            add(_x2+1, _y2+1, v);
        }
        void add2Dxy(int _x1, int _y1, int _x2, int _y2, int v) {
            add(_x1, _y1, v*(_x1*_y1));
            add(_x1, _y2+1, -v*(_x1*(_y2+1)));
            add(_x2+1, _y1, -v*(_x2+1)*_y1);
            add(_x2+1, _y2+1, v*(_x2+1)*(_y2+1));
        }
        void add2Dx(int _x1, int _y1, int _x2, int _y2, int v) {
            add(_x1, _y1, v*_x1);
            add(_x1, _y2+1, -v*(_x1));
            add(_x2+1, _y1, -v*(_x2+1));
            add(_x2+1, _y2+1, v*(_x2+1));
        }
        void add2Dy(int _x1, int _y1, int _x2, int _y2, int v) {
            add(_x1, _y1, v*_y1);
            add(_x1, _y2+1, -v*(_y2+1));
            add(_x2+1, _y1, -v*(_y1));
            add(_x2+1, _y2+1, v*(_y2+1));
        }

        ll sum(int x, int y) {
            ll tot = 0;
            for (int i = x; i > 0; i -= lowbit(i)) {
                for (int j = y; j > 0; j -= lowbit(j)) {
                    tot += bit[i][j];
                }
            } 
            return tot;
        }
        void add(int x, int y, int v) {
            for (int i = x; i <= MAXX; i += lowbit(i)) {
                for (int j = y; j <= MAXY; j += lowbit(j)) {
                    bit[i][j] += v;
                }
            }
        }
    void show() {
        cout << "Bit matrix " << endl;
        for (int i = 1; i <= MAXX; i ++) {
            for (int j = 1; j <= MAXY; j ++) {
                cout << bit[i][j] << " ";
            }
            cout << endl;
        }
    }
    void showOrigin() {
        cout << "Origin matrix: " << endl;
        for (int i = 1; i <= MAXX; i ++) {
            for (int j = 1; j <= MAXY; j ++) {
                cout << sum(i, j) << " ";
            }
            cout << endl;
        }
    }
    private:
        int bit[MAXN][MAXN];
        int lowbit(int x) {
            return x & (-x);
        }
        int MAXX, MAXY;
};

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void add(Bit2D & bit_diff, Bit2D & bit_xy, Bit2D & bit_x, Bit2D & bit_y,
        int _x1, int _y1, int _x2, int _y2, int v) {
    bit_diff.add2D(_x1, _y1, _x2, _y2, v);
}

ll get(Bit2D & bit_diff, Bit2D & bit_xy, Bit2D & bit_x, Bit2D & bit_y, 
        int x, int y) {
    ll tot = 0;
    return bit_diff.sum(x, y);
}

void solve() {
    cin >> M >> Q;
    Bit2D bit_diff(M, M), bit_xy(M, M), bit_x(M, M), bit_y(M, M);
    char op;
    int _x1, _x2, _y1, _y2, x, y;
    while (Q --) {
        cin >> op;
        if (op == 'Q') {
            cin >> x >> y;
            cout << get(bit_diff, bit_xy, bit_x, bit_y, x, y) % 2 << endl;
        } else if (op == 'C') {
            cin >> _x1 >> _y1 >> _x2 >> _y2;
            add(bit_diff, bit_xy, bit_x, bit_y, _x1, _y1, _x2, _y2, 1);
        }
    }    
    cout << endl;
}


int main() {
    quickread();
    cin >> T;
    while (T --) {
        solve();
    }  
    return 0;
}

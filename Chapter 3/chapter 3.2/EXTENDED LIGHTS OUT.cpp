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
const int MAXM = 5;
const int MAXN = 6;

const int M = 5;
const int N = 6;
int T;
int cnts[MAXM][MAXN];
int initST[MAXM];
int st[MAXM];
int bestMethod[MAXM];
int currMethod[MAXM];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int cnt_one(int num) {
    int cnt = 0;
    while (num) {
        cnt += (num&1);
        num >>= 1;
    }
    return cnt;
}

int flip(int num) {
    int res = 0;
    for (int i = 0; i < N; i ++) {
        res <<= 1;
        res |= (num >> i) & 1;
    }
    return res;
}
int get_next(int curr_op, int row) {
    st[row+1] ^= curr_op;
    int next_op = st[row];
    for (int i = 0; i < N; i ++) {
        int times = ((curr_op >> i) & 1) + ((curr_op >> (i + 1)) & 1) + (i ? ((curr_op >> (i - 1)) & 1):0);
        //cout << next_op << endl;
        next_op ^= ((times & 1) << i);
        //cout << i << ": " << times <<" " << next_op << endl;
    } 
    //cout << row << " " << curr_op << " " << next_op <<endl;
    return ((row == M - 1) && next_op) ? -1 : next_op;
}

void showbits(int x) {
    cout << x << ": ";
    for (int i = 0; i < N; i ++) cout << ((x >> i) & 1) << " ";
    cout << endl;
}

void solve() {
    int min_flip = 0x3f3f3f;
    for (int i = 0; i < (1 << N); i ++) {
        memcpy(st, initST, sizeof(st));
        int curr_filp = 0;
        int curr_op = flip(i);
        //cout << i << " " << curr_op  << endl;
        for (int j = 0; j < M; j ++) {
            currMethod[j] = curr_op;
            curr_filp += cnt_one(curr_op);
            curr_op = get_next(curr_op, j);
            //cout << j << " " <<curr_op << endl;
            if (curr_op == -1) {
                curr_filp += 0x3f3f3f;
                break;
            }
        }
        if (curr_filp < min_flip) {
            min_flip = curr_filp;
            memcpy(bestMethod, currMethod, sizeof(bestMethod));
        }
        //break;
    }
    if(min_flip >= 0x3f3f3f) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < M; i ++) {
            for (int j = 0; j < N; j ++) {
                if(j)cout << " ";
                cout << ((bestMethod[i] >> j) & 1);
            }
            cout << endl;
        }
    }
}

int main() {
    quickread();
    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < M; i++) {
            int curr_row = 0;
                for (int j = 0; j < N; j++) {
                    int x;
                    cin >> x;
                    curr_row |= (x << j);
                }
                initST[i] = curr_row;
                //cout << i <<" " << curr_row << endl;
                //showbits(initST[i]);
                //cout << i << " " << curr_row << endl;
            }
        cout << "PUZZLE #"<<t << endl;
        solve();
    }

    return 0;
}
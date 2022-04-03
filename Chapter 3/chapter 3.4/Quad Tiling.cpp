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
int N, M;
const int MAXST = (1 << 4);
bool st[MAXST];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

struct Matrix {
    int data[MAXST][MAXST];

    Matrix& operator+=(const Matrix& m) {
        for (int i = 0; i < MAXST; i ++) {
            for (int j = 0; j < MAXST; j ++) {
                data[i][j] += m.data[i][j];
                data[i][j] %= M;
            }
        }
        return *this;
    }

    Matrix& operator*=(const Matrix& m) {
        int d[MAXST][MAXST];
        for (int i = 0; i < MAXST; i ++) {
            for (int j = 0; j < MAXST; j ++) {
                d[i][j] = 0;
                for (int k = 0; k < MAXST; k ++) {
                   d[i][j] += data[i][k]*m.data[k][j]; 
                   d[i][j] %= M;
                }
            }
        }
        for (int i = 0; i < MAXST; i ++) {
            for (int j = 0; j < MAXST; j ++) {
                data[i][j] = d[i][j];
            }
        }
        return *this;
    }

    void show() {
        for (int i = 0; i < MAXST; i ++) {
            for (int j = 0; j < MAXST; j ++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

Matrix power(Matrix& m, int n) {
    Matrix res;
    for (int i = 0; i < MAXST; i ++) {
        for (int j = 0; j < MAXST; j ++) {
            if (i == j) {
                res.data[i][j] = 1;
            } else {
                res.data[i][j] = 0;
            }
        }
    }
    //cout << "hey!" << endl;
    //m.show();
    while (n) {
        //res.show();
        //cout << endl;
        if (n & 1) {
            res *= m;
        } 
        m *= m;
        n >>= 1;
    }

    return res;
} 

        
bool check(int i, int j) {
    if (i & j) return false;
    int c = (i | j);
    for (int i = 0; i <= 3; i ++) {
        if ((c >> i) & 1 != 0) continue;
        int cnt = 1;
        for (int j = i + 1; j <= 3; j ++) {
            if ((c >> j) & 1 != 0) break;
            cnt ++;
        }
        if (cnt & 1) return false;
    }
    return true;
}

int main() {
    quickread();
    for(int i = 0; i < (1 << 4); i ++) {
        int cnt = 0;
        st[i] = true;
        for(int j = 0; j < 4; j ++)
        {
            if((i >> j) & 1)
            {
                if(cnt & 1) st[i] = false;
                cnt = 0;
            }
            else cnt ++;
        }
        if(cnt & 1) st[i] = false;
    }
    while (cin >> N >> M, N || M) {
        Matrix m;
        for (int i = 0; i < MAXST; i ++) {
            for (int j = 0; j < MAXST; j ++) {
                if ((i & j) == 0 && st[i | j]) m.data[i][j] = 1;
                else m.data[i][j] = 0;
            }
        }
        Matrix res = power(m, N);
        //res.show();
        cout << res.data[0][0] << endl;
    }
    return 0;
}

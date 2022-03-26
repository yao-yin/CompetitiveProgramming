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
const int MAXN = 200010;
const int MAXM = 100010;
const int BUCKET_SIZE = 450;

int A[MAXN], N, M;

struct Bucket {
    int count;
    int prefix_sum;
} buckets[BUCKET_SIZE][BUCKET_SIZE];

struct Space {
    int X[MAXN], Y[MAXN];
    void insert(const int & x, const int & y) {
        X[y] = x;
        Y[x] = y;
    }

    void remove(const int & x, const int & y) {
        X[y] = -1;
        Y[x] = -1;
    }

    int getX(const int & y) {
        return X[y];
    }

    int getY(const int & x) {
        return Y[x];
    }

    void init() {
        memset(X, -1, sizeof X);
        memset(Y, -1, sizeof Y);
    }
} space;

void update_prefix_sum(int bx, int by) {
    int sum = (bx > 0 ? buckets[bx-1][by].prefix_sum : 0);
    for (int i = bx; i < BUCKET_SIZE; i ++) {
        sum += buckets[i][by].count;
        buckets[i][by].prefix_sum = sum;
    }
}

void add(int x, int y) {
    space.insert(x, y);
    int bx = x / BUCKET_SIZE;
    int by = y / BUCKET_SIZE;

    ++ buckets[bx][by].count;
    update_prefix_sum(bx, by);
}

void remove(int x, int y) {
    space.remove(x, y);
    int bx = x / BUCKET_SIZE;
    int by = y / BUCKET_SIZE;

    -- buckets[bx][by].count;
    update_prefix_sum(bx, by);
}

int count_sum(int x, int y) {
    int block_w = (x + 1) / BUCKET_SIZE;
    int block_h = (y + 1) / BUCKET_SIZE;

    int count = 0;
    for (int i = 0; i < block_h; i ++) {
        if (block_w > 0) {
            count += buckets[block_w -1][i].prefix_sum;
        }
    }
    for (int i = block_w*BUCKET_SIZE; i <= x; i++) {
        if (space.getY(i) != -1 && space.getY(i) < block_h * BUCKET_SIZE) {
            count ++;
        }
    }
    for (int i = block_h*BUCKET_SIZE; i <= y; i ++) {
        if (space.getX(i) != -1 && space.getX(i) <= x) count ++;
    }
    return count;
}

int count_inversion(int x, int y) {
    int count = 0;
    int intersection = count_sum(x, y);
    count += count_sum(x, N - 1) - intersection;
    count += count_sum(N - 1, y) - intersection;
    return count;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    while (cin >> N >> M) {
        space.init();
        memset(buckets, 0, sizeof(buckets));
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            A[i] --;
        }
        ll inversion = 0;
        for (int i = 0; i < N; i++) {
            add(i, A[i]);
            inversion += count_inversion(i, A[i]);
        }
        for (int i = 0; i < M; i ++) {
            int q;
            cin >> q;
            q --;
            cout << inversion << endl;
            inversion -= count_inversion(space.getX(q), q);
            remove(space.getX(q), q);
        }
    }    
    return 0;
}

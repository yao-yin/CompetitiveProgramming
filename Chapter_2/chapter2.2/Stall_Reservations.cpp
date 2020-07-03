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
const int N = 50010;
pii p[N];
int res[N];
int n, a, b;
//const int mod = 1e9+7;

struct Seg {
    int l, r, idx;
    Seg(int left, int right, int id) {
        idx = id;
        l = left;
        r = right;
    }
    Seg() {}
    bool operator < (const Seg & t) const {
        return l < t.l;
    }
} segs[N];

struct cmp {
    bool operator() (const Seg & a, const Seg & b) const {
        return a.r>= b.r;
    }
};

priority_queue<pii, vector<pii>, greater<pii> > pq;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    quickread();
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a >> b;
        segs[i] = Seg(a, b, i);
    }
    sort(segs, segs + n);
    int idx = 1;
    for(int i = 0; i < n; i ++) {
        int currl = segs[i].l;
        int currr = segs[i].r;
        int id = segs[i].idx;
        if(pq.empty() || pq.top().first >= currl) {
            pq.push(make_pair(currr, idx ++));
            res[id] = idx - 1;
        } else {
            int l = pq.top().first;
            int r = pq.top().second;
            pq.pop();
            res[id] = r;
            //cout << i <<": " << currl<< " " << l <<" "<<r<<  endl;
            pq.push(make_pair(currr, r));
        }
    }
    cout << pq.size() << endl;
    for(int i = 0; i < n; i ++) cout << res[i] << endl;
    return 0;
}
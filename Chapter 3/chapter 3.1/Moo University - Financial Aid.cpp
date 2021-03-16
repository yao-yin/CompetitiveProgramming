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
typedef pair<ll, ll> pii;
//const int mod = 1e9+7;
const int C = 100010;
pii calf[C];
ll n, c, f;
ll lhs[C], rhs[C];
ll inf = 0x3f3f3f3f3f3f;
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    quickread();
    cin >> n >> c >> f;
    for(int i = 1; i <= c; i ++) {
        cin >> calf[i].first >> calf[i].second;
    }
    sort(calf+1, calf+1+c);
    priority_queue<ll> pq;
    // lhs
    /*
    for(int i = 1; i <= c; i ++) {
        lhs[i] = pq.size()==half ? tot : inf;
        pq.push(calf[i].second);
        tot += calf[i].second;
        if(pq.size()>half)
        {
            //去掉一个学费最高的
            tot -= pq.top();
            pq.pop();
        }
    }
    */
    int half = n / 2;
    ll tot = 0;
    for(int i = 1; i <= c; i ++) {
        if(pq.size() < half) {
            lhs[i] = f;
            pq.push(calf[i].second);
            tot += calf[i].second;
        } else {
            lhs[i] = tot;
            pq.push(calf[i].second);
            tot += calf[i].second;
            tot -= pq.top();
            pq.pop();
        }
    }
    // rhs
    priority_queue<ll> q;
    tot = 0;
    for(int i = c; i >= 1; i --) {
        if(q.size() < half) {
            rhs[i] = f;
            q.push(calf[i].second);
            tot += calf[i].second;
        } else {
            rhs[i] = tot;
            q.push(calf[i].second);
            tot += calf[i].second;
            tot -= q.top();
            q.pop();
        }
    }
    int res = -1;
    /* show
    for(int i = 1; i <= c; i ++) {
        cout << i << " :" << calf[i].first <<" " << calf[i].second<<" "<< lhs[i] << " "<< rhs[i] <<  endl;
    }
    */
    
    for (int i = c; i >= 1; i --) {
        if(rhs[i] + lhs[i] + calf[i].second <= f) {
            res = calf[i].first;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
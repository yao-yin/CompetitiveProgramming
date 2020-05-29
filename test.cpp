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


inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void show(string & s) {
    for(int i = 1; i <= s.size(); i ++) {
        cout << s[i-1];
        if(i % 60 == 0) cout << endl;
    }
}

void solve() {
    int n;
    string s;
    deque<char> dq;
    cin >> n;
    char c;
    for(int i = 0; i < n; i ++) {
        cin >> c;
        dq.push_back(c);
    }
    while(!dq.empty()) {
        if(dq.front() < dq.back()) {
            s.push_back(dq.front());
            dq.pop_front();
        } else {
            s.push_back(dq.back());
            dq.pop_back();
        }
    }
    show(s);
}

int main()
{
    quickread();
    solve();
    return 0;
}
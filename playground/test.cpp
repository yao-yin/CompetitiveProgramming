#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
//const int mod = 1e9+7;
const int MAXN = 101;
const int MAXP = 10001;
bool res[MAXN][MAXP];
int T, P;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

double get_sqer(vector<int> & v) {
    double tot = 0.0;
    for (auto c: v) {
        tot += c;
    }
    tot /= (double)v.size();
    double er = 0.0;
    for (auto c: v) {
        er += (c - tot)*(c- tot);
    }
    return er;
}

int solve() {
    string S;
    for (int i = 1; i <= 100; i ++) {
        cin >> S;
        for (int j = 1; j <= 10000; j ++) {
            res[i][j] = (S[j-1] == '1');
        }
    }
    //problems
    vector<int> problems(10001, 0);
    for (int i = 1; i <= 10000; i ++) {
        for (int j = 1; j <= 100; j ++) {
            problems[i] += res[j][i];
        }
    }
    vector<pii> probs;
    for (int i = 1; i <= 10000; i ++) {
        probs.push_back({problems[i],i});
    }
    sort(probs.begin(), probs.end());
    int x = 2500;
    vector<vector<int>> player(101, vector<int> (10000/x, 0));
    for (int j = 1; j <= 100; j ++) {
        int idx = 0;
        for (int i = 0; i < 10000; i += x) {
            for (int k = i; k < i + x; k++) {
                player[j][idx] += res[j][probs[k].second];
            }
            idx ++;
        }
    }
    /*cout << endl;
    for (int i = 0; i <= 100; i ++) {
        for (int j = 0; j < 10; j ++) {
            cout << player[i][j] <<" ";
        }
        cout << endl;
    }*/
    vector<pdi> sqer;
    for (int i = 1; i <= 100; i ++) {
        if (player[i][player[i].size()-1] >= x/2 - 500) {
            //sqer.push_back({get_sqer(player[i]), i});
            sqer.push_back({player[i][0]+player[i][1], i});
        }
    }
    sort(sqer.begin(), sqer.end());
    return sqer[0].second;
}

int main() {
    quickread();
    cin >> T >> P;
    for (int i = 1; i <= T; i ++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}

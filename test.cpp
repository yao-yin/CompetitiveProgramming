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
//const int mod = 1e9+7;

class Solution {
public:
    using pii = pair<int, int>;
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        check.insert({0, 0});
        for(auto i :path) {
            if(i == 'N') {
                x += 1;
                if(check.count({x, y})) return false;
                check.insert({x, y});
            }
            if(i == 'S') {
                x -= 1;
                if(check.count({x, y})) return false;
                check.insert({x, y});
            }
            if(i == 'W') {
                y += 1;
                if(check.count({x, y})) return false;
                check.insert({x, y});
            }
            if(i == 'E') {
                y -= 1;
                if(check.count({x, y})) return false;
                check.insert({x, y});
            }
        }
        return true;
    }
    set<pii> check;
};

class T2Solution {
public:
    bool solve(vector<int> & arr, int k) {
        unordered_map<int, int> cnts;
        for(auto num: arr) {
            int mod = ((num % k) + k) % k;
            cnts[mod] ++;
        }
        for(auto [mod, num]: cnts) {
            if(mod == 0) {
                if(num & 1) return false;
            } else {
                if(num != cnts[k - mod]) return false;
            }
        }
        return true;
    }
};

class T4Solotion {
    int cal(vector<int> & nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9+7;
        for(int i = 0; i < nums.size(); i ++) {
            int j = getIndex(nums, target - nums[i]);
            res += get(i, j);
            res %= mod;
        }
        return res;
    }
    int getIndex()
}
int main()
{
    cout << (-4)%3 << endl;    
    return 0;
}

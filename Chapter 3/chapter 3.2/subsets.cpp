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

const int maxn = 2e5 + 10;
const int MAXN = 1e6 + 10;
const int INF = -0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1010;
 
ll n, ans;
ll a[N];
 
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main(){
	while(cin >> n, n){
		memset(a, 0, sizeof(a)); 
        ans = INF;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);
		for (int i = n-1; i >= 0; i--){
			for (int j = n-1; j >= 0; j--){
				if (i == j) continue;
				ll sum = a[i]-a[j];
				for (int l = 0, r = j-1; l < r;){
					if(a[l] + a[r] == sum){
						ans = a[i]; break;
					}
					if (a[l] + a[r] > sum) r--;
					else l++;
				}
				if (ans != INF) break;
			}
			if (ans != INF) break;
		}
		if(ans == INF) cout << "no solution" << endl;
		else cout << ans << endl;
	}
	return 0;
}
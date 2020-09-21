/*
This problem has a very tight limit on time and space , but I am tired on constant optimization.
So I use others's code to pass. Original: https://www.cnblogs.com/whhh/p/13049713.html
*/
/*
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
const int N = 1e5 + 10;
int n,m,t;
int dist[N];
int parent[N];
bool st[N];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

pii find(int x) {
    if (parent[x] == x) {
        return make_pair(x, 0);
    } else {
        pii res = find(parent[x]);
        parent[x] = res.first;
        dist[x] = (dist[x] + res.second) & 1;
        return make_pair(parent[x], dist[x]);
    } 
}

void init() {
    memset(st, 0, sizeof st);
    memset(dist, 0, sizeof dist);
    for (register int i = 1; i <= n; i ++) {
        parent[i] = i;
    }
}

void solve() {
    cin >> n >> m;
    init();
    char op;
    int a, b;
    while (m --) {
        getchar();
        cin >> op >> a >> b;
        if (op == 'A') {
            // query
            if (st[a] && st[b]) {
                pii resa = find(a);
                pii resb = find(b);
                if (resa.first != resb.first) {
                    cout << "Not sure yet.\n";
                } else {
                    if (resa.second == resb.second) {
                        cout << "In the same gang.\n";
                    } else {
                        cout << "In different gangs.\n";
                    }
                }
            } else {
                cout << "Not sure yet.\n";
            }
        } else if (op == 'D') {
            // modify
            st[a] = true;
            st[b] = true;
            pii resa = find(a);
            pii resb = find(b);
            parent[resa.first] = resb.first;
            dist[resa.first] = resa.second == resb.second;
        }
    }
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include <sstream>
#include<vector>
#include<cmath>    
#include<stack>
#include<time.h>
#include<ctime>
using namespace std;
#define inf 1<<30
#define eps 1e-7
#define LD long double
#define LL long long
#define maxn 1000000005
int pre[200009] = {};
int rootsearch(int root)
{
    int son;
    son = root;
    while (root != pre[root])//这个数不是领导，继续往下找
    {
        root = pre[root];
    }
    while (son != root)//路径压缩，把找到的下级数全部指向最高领导
    {
        int temp = pre[son];
        pre[son] = root;
        son = temp;
    }
    return root;//返回最高领导
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N, M, a, b;
        char ch;    
        scanf("%d%d", &N, &M);
        getchar();
        for (int i = 1; i <= 2 * N; i++)//初始化一个两倍的数组
        {
            pre[i] = i;
        }
        while(M--)
        {
            scanf("%c %d %d", &ch, &a, &b);//用cin会超时，别问我怎么知道的。。。
            getchar();
            if (ch == 'D')
            {
                pre[rootsearch(a + N)] = rootsearch(b);//把a+N和b联系在一起
                pre[rootsearch(b + N)] = rootsearch(a);//把b+N和a联系在一起
            }
            else
            {
                if (rootsearch(a) == rootsearch(b)||rootsearch(a+N)==rootsearch(b+N))//如果a,b或a+N,b+N的根节点一致
                {
                    printf("In the same gang.\n");
                }
                else if (rootsearch(a) == rootsearch(b + N) || rootsearch(a + N) == rootsearch(b))//如果a,b+N或a+N,b的根节点一致
                {
                    printf("In different gangs.\n");
                }
                else//两个人没有任何关系
                {
                    printf("Not sure yet.\n");
                }
            }
        }
    }
}
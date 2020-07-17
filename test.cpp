#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define Mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x,y) memset(x,y,sizeof(x))
#define Maxn 1000005
using namespace std;
int n;
int w[Maxn];
int cnt=0;
int dp[Maxn];
int main()
{
    scanf("%d",&n);
    for(int i=0;(1<<i)<=n;i++)//构造所有物品
        w[cnt++]=(1<<i);
    dp[0]=1;
    for(int i=0;i<cnt;i++)
        for(int j=w[i];j<=n;j++)
            dp[j]=(dp[j]+dp[j-w[i]])%1000000000;//取余

    printf("%d\n",dp[n]);
    return 0;
}
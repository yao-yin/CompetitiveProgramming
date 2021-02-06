#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int land[205][205],sea[205][205],tar[1005],dp[1005][205];
int main()
{
    int n,m,i,j,k,r;
    while(cin>>n>>m&&(n+m)){
        memset(land,0x3f,sizeof(land));memset(sea,0x3f,sizeof(sea));memset(dp,0x3f,sizeof(dp));
        for(i=1;i<=m;i++){
            int a,b,c;string str;
            cin>>a>>b>>c>>str;
            if(str=="S")
                sea[a][b]=sea[b][a]=c;
            else
                land[a][b]=land[b][a]=c;
        }
        for(i=1;i<=n;i++)land[i][i]=sea[i][i]=0;//不要忘了这个..
        cin>>r;for(i=1;i<=r;i++)cin>>tar[i];
        for(k=1;k<=n;k++)//floyd初始化,至于那些不可能的,初始化完了肯定还是无穷大不可能
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++){
                    land[i][j]=min(land[i][j],land[i][k]+land[k][j]);
                    sea[i][j]=min(sea[i][j],sea[i][k]+sea[k][j]);
                }
        dp[1][tar[1]]=0;//初始化
        for(i=2;i<=r;i++)//从2开始也没问题
            for(j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i-1][j]+land[tar[i-1]][tar[i]]);//单纯走陆路的情况,从tar[i-1]到tar[i]
                for(k=1;k<=n;k++){//回到船停的j镇,水路从j到k,陆路k到tar[i],枚举k
                    dp[i][k]=min((long long)dp[i][k],(long long)dp[i-1][j]+land[tar[i-1]][j]+sea[j][k]+land[k][tar[i]]);
                    //注意这里一定是dp[i][k]而不是dp[i][j]
                }
                //cout << tar[i] << " " << j << ": " << dp[i][j] << endl;
            }
        int ans=0x7f7f7f7f;
        for(i=1;i<=n;i++)
            ans=min(ans,dp[r][i]);
        cout<<ans<<endl;
    }

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 510;
int tri[N][N];
int dp[N][N];

int main()
{
    int row;
    cin >> row;
    for (int i = 1; i <= row; i ++) 
    {
        for (int j = 1; j <= i; j ++)
        {
            cin >> tri[i][j];
        }
    }
    for(int i = 0; i <= row; i ++)
    {
        dp[i][0] = -999999;
        dp[i][i+1] = -999999;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
        }
    }
    int temp = dp[row][1];
    for (int i = 1; i <= row; i ++)
    {
        temp = max(temp,dp[row][i]);
    }
    cout << temp;
    return 0;
}
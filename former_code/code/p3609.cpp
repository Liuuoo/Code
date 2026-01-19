#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1e5+10;
int dp[N][25][3]; //dp_i_j_k表示前i个位置j次改变且第i个位置为k的最大赢值
int p0[N],p1[N],p2[N];
int max(int a,int b,int c)
{
    return max(a,max(b,c));
}

int main() 
{
    cin>>n>>k;
    vector<int> vec(n+1);
    
    for(int i=1;i<=n;i++) 
    {
        char c; cin>>c;
        p0[i]=p0[i-1];
        p1[i]=p1[i-1];
        p2[i]=p2[i-1];
        if(c=='H') vec[i]=0,p0[i]++;
        else if(c=='S') vec[i]=1,p1[i]++;
        else vec[i]=2,p2[i]++;
    }
    memset(dp,INT_MIN,sizeof(dp));

    for(int j=0;j<=k;j++)
    {
        for(int l=0;l<3;l++)
        dp[0][j][l]=0;
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        dp[i][0][0]=p0[i];
        dp[i][0][1]=p1[i];
        dp[i][0][2]=p2[i];
        ans=max(p0[i],p1[i],p2[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j][0]=max(dp[i-1][j-1][1],dp[i-1][j-1][2],dp[i-1][j][0])+(vec[i]==0);
            dp[i][j][1]=max(dp[i-1][j-1][0],dp[i-1][j-1][2],dp[i-1][j][1])+(vec[i]==1);
            dp[i][j][2]=max(dp[i-1][j-1][0],dp[i-1][j-1][1],dp[i-1][j][2])+(vec[i]==2);
            for(int k=0;k<3;k++) 
            {
                ans=max(ans,dp[i][j][k]);
            }
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=k;j++)
    //     {
    //         cout<<i<<" "<<j<<": ";
    //         for(int k=0;k<3;k++)
    //         {
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }
    cout<<ans;
}
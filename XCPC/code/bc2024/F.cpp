#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1234;
int dp[N][N][2];

int re_calc(int x)
{
    string s;
    while(x)
    {
        s+=(x%2)+'0';
        x/=2;
    }
    reverse(s.begin(),s.end());
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans+=(s[i]-'0')*pow(2,i);
    }
    return ans;
}

signed main()
{
    memset(dp,-0x3f,sizeof dp);
    int n,m;
    cin>>n>>m;
    int sum=0;
    int a[n+1];
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
        dp[i][0][0]=sum;
        // cout<<re_calc(a[i])<<" ";
    }
    dp[0][0][0]=0;
    // for(int i=1;i<=n;i++) 
    // {
    //     cout<<re_calc(a[i])<<" ";
    //     // cout<<re_calc(a[i])<<" ";
    // }
    //cout<<'\n';

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j][0]=max(dp[i-1][j][1],dp[i-1][j][0])+a[i];
            //dp[1][1][0]=-0x3f3f3f3f;
            if(j>=1)
            dp[i][j][1]=max({dp[i-1][j-1][0],dp[i-1][j][1],dp[i-1][j-1][1]})+re_calc(a[i]);
            /// cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<'\n';
        }
    }
    int ans=INT64_MIN;
    for(int j=0;j<=m;j++)
    {
        // cout<<max(dp[n][j][0],dp[n][j][1])<<" ";
        ans=max(ans,dp[n][j][0]);
        ans=max(ans,dp[n][j][1]);
    }
    cout<<ans;
}
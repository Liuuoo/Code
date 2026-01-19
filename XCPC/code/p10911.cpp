#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1234;
int a[N];
int b[N];
int dp[N][N][2];
int pre_a[N];
int pre_b[N];

string to_bit(int n) 
{
    string s;
    while(n)
    {
        s+=(n%2+'0');
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}

int r_bit(int n)
{
    string s=to_bit(n);
    // cout<<s<<"\n";
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans+=pow(2,i)*(s[i]-'0');
    }
    return ans;
}

signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        a[i]=x;
        pre_a[i]=pre_a[i-1]+x;
        b[i]=r_bit(x);
        pre_b[i]=pre_b[i-1]+b[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0][1]=pre_b[i];
        dp[i][0][0]=pre_a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j][0]=max(dp[i-1][j][1],dp[i-1][j][0])+a[i];
            dp[i][j][1]=max(dp[i-1][j-1][0],dp[i-1][j][1])+b[i];
        }
    }
    int ans=INT_MIN;

    for(int j=0;j<=m;j++)
    {
        //cout<<dp[n][j][1]<<' ';
        ans=max(ans,max(dp[n][j][0],dp[n][j][1]));
    }
    cout<<ans;
}
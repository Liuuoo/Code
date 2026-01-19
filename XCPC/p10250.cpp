#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100;
int dp[N];
signed main()
{
    int n;
    cin>>n;
    dp[n]=0;
    dp[n-1]=1;
    dp[n-2]=2;
    dp[n-3]=4;
    for(int i=n-4;i>=0;i--)
    {
        dp[i]=dp[i+1]+dp[i+2]+dp[i+3];
    }
    cout<<dp[0];
}
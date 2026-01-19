#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=33;
int dp[N][N];
signed main() {
    int n,m;
    cin>>n>>m;
    dp[1][1]=1;
    dp[1][n-1]=1;
    for(int i=2;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][(j-1+n)%n]+=dp[i-1][j];
            dp[i][(j+1)%n]+=dp[i-1][j];
        }
    }
    //for(int i=0;i<n;i++) cout<<dp[m][i]<<" ";
    cout<<dp[m][0];
}
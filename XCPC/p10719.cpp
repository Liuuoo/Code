#include<bits/stdc++.h>
using namespace std;
int box[123][123];
int pre_sum[123][123];

int calc(int i,int j)
{
    return (pre_sum[i-1][j]+pre_sum[i][j-1]-pre_sum[i-1][j-1]);
}

int jud(int a,int b,int c,int d)
{
    return pre_sum[c][d]-pre_sum[c][b-1]-pre_sum[a-1][d]+pre_sum[a-1][b-1];
}

int main()
{
    int n,m,kk;
    cin>>n>>m>>kk;
    string s[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            box[i][j]=s[i][j-1]-'0';
        }
    }
    int ans=INT_MAX;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            pre_sum[i][j]=box[i][j]+calc(i,j);
            // cout<<pre_sum[i][j];
        }
        // cout<<'\n';
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=i;k<=n;k++)
            {
                for(int l=j;l<=m;l++)
                {
                    if(jud(i,j,k,l)>=kk)
                    {
                        ans=min(ans,(k-i+1)*(l-j+1));
                    }
                }
            }
        }
    }
    if(ans==INT_MAX) ans=0;
    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;

bool jud(int a,int b,int c,int d,vector<vector<int>> vec)
{
    for(int i=a;i<=c;i++)
    {
        for(int j=b;j<=d;j++)
        {
            if(vec[i][j]==0) return false;
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> bod(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>bod[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=i;k<=n;k++)
            {
                for(int l=j;l<=m;l++)
                {
                    // ij-lefup
                    // kl-ridown
                    if(jud(i,j,k,l,bod))
                    {
                        ans=max(ans,(k-i+1)*(l-j+1));
                    }
                }
            }
        }
    }
    cout<<ans;
}
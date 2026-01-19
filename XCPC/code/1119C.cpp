#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    int b[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            a[i][j]=x;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            b[i][j]=x;
        }
    }
    int c[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {  
            c[i][j]=(a[i][j]==b[i][j]);
            // cout<<c[i][j]<<" ";
        }
        // cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        int tmp=0;
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]==0)
            {
                tmp++;
            }
        }
        if((tmp&1)!=0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int j=1;j<=m;j++)
    {
        int tmp=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i][j]==0)
            {
                tmp++;
            }
        }
        if((tmp&1)!=0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}
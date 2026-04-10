#include<bits/stdc++.h>
using namespace std;

const int N=100;
int a[N][N];

int main()
{
    memset(a,-1,sizeof(a));
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j && i<=k)
            {
                a[i][j]=0;
            }
        }
    }
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==-1)
            {
                if(j+1<=n&&a[i][j+1]==-1)
                {
                    a[i][j]=cnt;
                    a[i][j+1]=cnt++;
                }
                else if(i+1<=n && a[i+1][j]==-1)
                {
                    a[i][j]=cnt;
                    a[i+1][j]=cnt++;
                }
                else a[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,z,n,m;
    int cnt=0;
    cin>>x>>y>>z>>n>>m;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=m;k++)
            {
                if(i+j+k*z>m) break;
                if(x*i+y*j+k==n&&i+j+k*z==m)
                {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
}
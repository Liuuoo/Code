#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    map<int,int> M;
    while(m--)
    {
        int j;
        cin>>j;
        if(j==1)
        {
            int x,y;
            cin>>x>>y;
            M[x]+=y;
        }
        else 
        {
            int p;
            cin>>p;
            int ans=a[p];
            for(int i=1;i<=sqrt(p);i++)
            {
                if(p%i==0)
                {
                    ans+=M[i];
                    if(i*i!=p) ans+=M[p/i];
                }
            }
            cout<<ans<<'\n';
        }
    }
}
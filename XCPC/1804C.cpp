#include<bits/stdc++.h>
using namespace std;
#define int long long
bool solve(int n,int x,int p)
{
    for(int i=1;i<=min(p,2*n);i++)
    {
        x+=i;
        x%=n;
        if(x==0)
        {
            return 1;
        }
    }
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int n,x,p;
        cin>>n>>x>>p;
        bool ans1=solve(n,x,p);
        if(ans1) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
}
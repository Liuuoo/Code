#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    bool jud=0;
    if(a==x||b==y) jud=1;

    if(!jud||a<x||b>y)
    {
        cout<<"No\n";
    }
    else 
    {
        if(b==y)
        {
            while(x)
            {
                if((x&1)!=(a&1) && (x&1)==1)
                {
                    cout<<"No\n";
                    return;
                }
                x>>=1;
                a>>=1;
            }
        }
        else
        {
            while(b)
            {
                if((b&1)!=(y&1) && (b&1)==1)
                {
                    cout<<"No\n";
                    return;
                }
                b>>=1;
                y>>=1;
            }
        }
        
        cout<<"Yes\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    
}
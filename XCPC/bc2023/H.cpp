#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
vector<pair<int,int>> vec;

signed main()
{
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    
    while(m--)
    {int ans=0;
        int x,y;
        cin>>x>>y;
        for(auto it:vec)
        {
            if(it.first<y && it.second>x)
            {

                if(it.first>=x||it.second<=y)
                {
                    ans++;
                }
                else 
                {
                    if(it.first<x)
                    {
                        int tmp=it.second-x;
                        int ln=it.second-it.first;
                        if(ln/tmp>=2) ans++;
                    }
                    else 
                    {
                        int tmp=y-it.first;
                        int ln=it.second-it.first;
                        if(ln/tmp>=2) ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}
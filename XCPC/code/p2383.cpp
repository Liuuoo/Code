#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int arr[n+1];
    bool vis[n+1];
    int tmp[n+1];
    bool get=false;
    int avg=0;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        avg+=arr[i];
        vis[i]=false;
    }
    if(avg%4==0)
    {
        avg/=4;
        function<void(int)> dfs=[&](int x)->void
        {
            // cout<<x<<'\n';
            int t=0;
            for(int i=0;i<x;i++)
            {
                t+=tmp[i];
                if(t>avg) return;
                if(t==avg) t=0;
            }

            if(get==true) return;
            if(x==n) 
            {
                get=true;
                return;
            }
            for(int i=0;i<n;i++)
            {
                if(!vis[i]) 
                {
                    tmp[x]=arr[i];
                    vis[i]=true;
                    dfs(x+1);
                    vis[i]=false;
                }
            }
        };
        dfs(0);
    }
    if(!get) cout<<"no\n";
    else cout<<"yes\n";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    int tmp=0;
    int jud=false;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1) 
        {
            tmp=0;
            jud=false;
        }
        else if(x==0)
        {
            if(jud) 
            {
                jud=false;
                continue;
            }
            else tmp++;
        }
        if(tmp==k)
        {
            tmp=0;
            ans++;
            jud=true;
        }
    }
    cout<<ans<<'\n';
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
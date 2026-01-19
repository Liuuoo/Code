#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,d,m;
    cin>>n>>d>>m;
    vector<int>a(n+1);
    int cnt=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]) cnt++;
    }
    vector<int>ans(n+1);
    if(cnt==n)
    {
        if(m%2!=0)
        {
            cout<<"No\n";
        }
        else 
        {
            for(int i=1;i<n;i++)
            {
                ans[i]=0;
            }
            ans[n-1]=m;
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
            cout<<'\n';
        }
    }
    else 
    {
        int t=-1;
        for(int i=n;i>=1;i--)
        {
            if(a[i]==0)
            {
                t=i;
                break;
            }
        }
        a[1]==1?ans[1]=0:ans[1]=1;
        
        int B=0;
        m-=ans[1];

        for(int i=2;i<t;i++)
        {
            if(m<0) 
            {
                cout<<"No\n";
                break;
            }
            if(a[i]==a[i-1]) 
            {
                ans[i]=ans[i-1];
            }
            else 
            {
                if(a[i]==0)
                {
                    ans[i]=ans[i-1]+1;
                }
                else 
                {
                    B+=d;
                    ans[i]=B;
                }
            }
            m-=ans[i];
        }
        for(int i=1;i<t;i++) cout<<ans[i]<<" ";
        cout<<'\n';

        

    }
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
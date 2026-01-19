#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    int a[n+1];
    int t=-1;
    set<int>S;
    int ans=INT64_MIN;
    vector<pair<int,int>> ln;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        int tmp=a[i]+i;
        ln.push_back({tmp,i});
    }
    sort(ln.begin(),ln.end());
    for(int i=0;i<n;i++)
    {
        if(ln[i].first==n) 
        {
            t=i;
            S.insert(n);
            break;
        }
    }
    if(t==-1) cout<<n<<"\n";
    else 
    {
        for(int i=t;i<n;i++)
        {
            int f=ln[i].first;
            int s=ln[i].second;
            if(S.find(f)!=S.end())
            {
                int tmp=f+s;
                ans=max(ans,tmp);
                S.insert(tmp);
            }
        }
        cout<<ans<<'\n';
    }
    
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
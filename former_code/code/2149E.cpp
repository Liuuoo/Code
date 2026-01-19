#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Map
{
    int sz;
    Map()
    {
        sz=0;
    }
    map<int,int> S;
    void insert(int x)
    {
        if(S[x]==0) 
        {
            sz++;
        }
        S[x]++;
    }
    void erase(int x)
    {
        S[x]--;
        if(S[x]==0)
        {
            S.erase(x);
            sz--;
        }
    }
    int size()
    {
        return sz;
    }
};

void solve()
{
    int n,k,l,r;
    cin>>n>>k>>l>>r;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    Map w1,w2;
    int y1=1,y2=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(y1<=n&&w1.size()!=k)
        {
            w1.insert(a[y1]);
            y1++;
        }
        while(y2<=n)
        {
            w2.insert(a[y2]);
            y2++;
            if(w2.size()>k)
            {
                w2.erase(a[y2-1]);
                y2--;
                break;
            }
        }
        int minlen=y1-i;
        int maxlen=y2-i;
        if(w1.size()==k&&w2.size()==k) ans+=max(min(maxlen,r)-max(minlen,l)+1,0ll);
        w1.erase(a[i]);
        w2.erase(a[i]);

    }
    cout<<ans<<'\n';
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
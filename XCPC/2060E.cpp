#include<bits/stdc++.h>
using namespace std;
#define int long long

struct UF
{
    vector<int>fa;
    UF(int n)
    {
        fa.resize(n+10);
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    int find(int x)
    {
        if(fa[x]==x) return x;
        else return fa[x]=find(fa[x]);
    }
    void unity(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a==b) return;
        else fa[a]=b;
    }
};

void solve()
{
    int n,m1,m2;
    cin>>n>>m1>>m2;
    vector<pair<int,int>> vec;
    while(m1--)
    {
        int a,b;
        cin>>a>>b;
        vec.push_back({a,b});
    }
    UF uf(n+1);
    while(m2--)
    {
        int u,v;
        cin>>u>>v;
        uf.unity(u,v);
    }
    map<int,int>M;
    for(int i=1;i<=n;i++)
    {
        M[uf.find(i)]++;
    }
    int ans=0;
    UF uf2(n+1);
    for(auto x:vec)
    {
        int a=x.first;
        int b=x.second;
        if(uf.find(a)!=uf.find(b))
        {
            ans++;
        }
        else 
        {
            int tmp=uf.find(a);
            if(uf2.find(a)!=uf2.find(b))
            {
                M[tmp]--;
                uf2.unity(a,b);
            }
        }
    }
    for(auto x:M)
    {
        ans+=(x.second-1);
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
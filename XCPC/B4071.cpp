#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;

int jud(int fin,vector<multiset<int>> vec)
{
    int ans=0;
    int ini=vec[1].size();
    for(int i=2;i<=n;i++)
    {
        int nd=vec[i].size()-(fin-1);
        for(int j=0;j<nd;j++)
        {
            ans+=*vec[i].begin();
            vec[i].erase(vec[i].begin());
            ini++;
        }
    }
    if(ini>fin) return -1;
    else 
    {
        if(ini==fin) return ans;
        else 
        {
            int nd=fin-ini;
            multiset<int> tmp;
            for(int i=2;i<=n;i++)
            {
                for(auto x:vec[i]) tmp.insert(x);
            }
            for(int i=0;i<nd;i++)
            {
                ans+=*tmp.begin();
                tmp.erase(tmp.begin());
            }
            return ans;
        }
    }
}

signed main()
{
    cin>>n>>m;
    int MAXN=0;
    vector<multiset<int>> vec(n+1);
    for(int i=0;i<m;i++)
    {
        int p,c;
        cin>>p>>c;
        vec[p].insert(c);
    }
    int ans=INT64_MAX;
    for(int i=max((int)vec[1].size(),1ll);i<=m;i++)
    {
        int tmp=jud(i,vec);
        if(tmp!=-1) 
        {
            ans=min(ans,tmp);
        }
    }
    cout<<ans;
}
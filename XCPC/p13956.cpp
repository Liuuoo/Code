#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>m>>n;
    vector<int> fin(n+10,0);
    vector<int> cnt(m+10,0);
    vector<int> ans(m+10);
    for(int i=1;i<=m;i++) ans[i]=i;
    int idx=0;
    vector<vector<int>> vec;
    vec.resize(m+1);
    bool v[n+1]={false};
    for(int i=1;i<=m;i++)
    {
        int p;
        cin>>p;
        cnt[i]=p;
        bool jud1=true;
        bool jud2=true;
        
        for(int j=1;j<=p;j++)
        {
            int x;
            cin>>x;
            if(fin[x]) jud1=false;
            if(v[x]) 
            {
                jud2=false;
            }
            vec[i].push_back(x);
            fin[x]=i;
            v[x]=true;
        }
        if(i!=1&&jud1)
        {
            idx=i;
        }
    }

    set<int> vv;
    for(int i=1;i<=m;i++)
    {
        bool jud2=true;
        for(auto x:vec[i]) 
        {
            if(vv.find(x)!=vv.end())
            {
                if(fin[x]==i)
                {
                    jud2=false;
                    break;
                }
            }
        }
        vv.clear();
        for(auto x:vec[i]) 
        {
            vv.insert(x);
        }
        if(i!=1&&jud2)
        {
            idx=i;
        }
    }
    vector<int> vis(m+10,0);
    for(int i=1;i<=n;i++)
    {
        vis[fin[i]]++;
    }
    bool can=false;
    if(m==1)
    {
        cout<<"No";
        return;
    }
    if(idx) 
    {
        swap(ans[idx],ans[idx-1]);
        can=true;
    }
    else 
    {
        for(int i=1;i<=m;i++)
        {
            if(!vis[i]) // this num i all miss
            {
                if(i!=1) 
                {
                    swap(ans[i],ans[i-1]);
                    can=true;
                    break;
                }
            }
        }
        if(!can)
        {
            vector<int> tmp(n+1,0);
            for(int i=0;i<vec[2].size();i++)
            {
                int x=vec[2][i];
                tmp[x]=2;
            }
            for(int i=0;i<vec[1].size();i++)
            {
                int x=vec[1][i];
                tmp[x]=1;
            }
            for(int i=3;i<=m;i++)
            {
                for(int j=0;j<vec[i].size();j++)
                {
                    int x=vec[i][j];
                    tmp[x]=i;
                }
            }
            bool flag=false;
            for(int i=1;i<=n;i++)
            {
                if(tmp[i]!=fin[i])
                {
                    flag=true;
                }
            }
            if(!flag)
            {
                swap(ans[1],ans[2]);
                can=true;
            }
        }
    }
    if(can)
    {
        cout<<"Yes\n";
        for(int i=1;i<=m;i++) cout<<ans[i]<<(i!=m?" ":"");
    }
    else cout<<"No";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
        cout<<(T!=0?"\n":"");
    }
}
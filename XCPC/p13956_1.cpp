#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<set<int>> vec) // n-lenth of arr
{
    // int n,m;
    // cin>>m>>n;
    int m=vec.size()-1; // size of querrys
    cout<<m<<" "<<n<<'\n';
    vector<int> fin(n+10,0);
    vector<int> cnt(m+10,0);
    vector<int> ans(m+10);
    for(int i=1;i<=m;i++) ans[i]=i;
    int idx=0;
    vector<vector<int>> vecc;
    vecc.resize(m+1);
    
    for(int i=1;i<=m;i++)
    {
        int p=vec[i].size();
        cout<<p<<" ";
        // cin>>p;
        cnt[i]=p;
        bool jud1=true;
        

        for(int j=1;j<=p;j++)
        {
            int x=*vec[i].begin();
            vec[i].erase(vec[i].begin());
            cout<<x<<" ";
            vecc[i].push_back(x);
            // cin>>x;
            if(fin[x]) jud1=false;
            fin[x]=i;
        }
        cout<<'\n';
        if(i!=1&&jud1)
        {
            idx=i;
        }
    }

    set<int> v;
    for(int i=1;i<=m;i++)
    {
        bool jud2=true;
        for(auto x:vecc[i]) 
        {
            if(v.find(x)!=v.end())
            {
                if(fin[x]==i)
                {
                    jud2=false;
                    break;
                }
            }
        }
        v.clear();
        for(auto x:vecc[i]) 
        {

            v.insert(x);
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
        return 0;
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
                for(int i=0;i<vecc[2].size();i++)
                {
                    int x=vecc[2][i];
                    tmp[x]=2;
                }
                for(int i=0;i<vecc[1].size();i++)
                {
                    int x=vecc[1][i];
                    tmp[x]=1;
                }
                for(int i=3;i<=m;i++)
                {
                    for(int j=0;j<vecc[i].size();j++)
                    {
                        int x=vecc[i][j];
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
        return 1;
    }
    else 
    {
        cout<<"No";
        return 0;
    }
}

int solve2(int n,vector<set<int>> vec)
{
    int m=vec.size()-1;
    vector<pair<int,set<int>>> bod;
    bod.resize(m+1);
    vector<int> fin(n+10,0);
    for(int i=1;i<=m;i++)
    {
        bod[i]={i,vec[i]};
    }
    for(int i=1;i<=m;i++)
    {
        int p=vec[i].size();
        for(int j=1;j<=p;j++)
        {
            int x=*vec[i].begin();
            vec[i].erase(vec[i].begin());
            fin[x]=i;
        }
    }
    vector<pair<int,set<int>>> bod2=bod;
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            bool flag=false;
            vector<int> tmp(n+10,0);
            swap(bod[i],bod[j]);
            for(int k=1;k<=m;k++)
            {
                int p=bod[k].second.size();
                for(int l=1;l<=p;l++)
                {
                    tmp[*bod[k].second.begin()]=bod[k].first;
                    bod[k].second.erase(bod[k].second.begin());
                }
            }
            bod=bod2;
            for(int k=1;k<=n;k++)
            {
                if(tmp[k]!=fin[k])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                cout<<i<<" "<<j<<'\n';
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    srand(time(0));
    int T=112123;
    // cin>>T;
    while(T--)
    {
        vector<set<int>> vec;
        int n=rand()%50+1; // position
        int m=rand()%n+1; // querrys
        vec.resize(m+1);
        for(int i=1;i<=m;i++)
        {
            int p=rand()%n+1;
            for(int j=1;j<=p;j++)
            {
                vec[i].insert(rand()%n+1);
            }
        }
        int ans1=solve(n,vec);
        int ans2=solve2(n,vec);
        if(ans1!=ans2)
        {
            break;
        }
        cout<<(T!=0?"\n":"");
    }
}
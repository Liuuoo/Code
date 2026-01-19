#include<bits/stdc++.h>
using namespace std;

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
    int n,m;
    cin>>m>>n;
    vector<set<int>> vec;
    vec.resize(m+1);
    for(int i=1;i<=m;i++)
    {
        int p;
        cin>>p;
        for(int j=1;j<=p;j++)
        {
            int x; cin>>x;
            vec[i].insert(x);
        }
    }
    int ans2=solve2(n,vec);
}
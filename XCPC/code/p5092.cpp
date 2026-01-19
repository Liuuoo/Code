#include<bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> fa,dist,len;
    DSU(int n)
    {
        fa.resize(n+1);
        dist.resize(n+1,0);
        len.resize(n+1,1); //该节点下方块数
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
    }
    int find(int x)
    {
        if(fa[x]!=x) 
        {
            int root=find(fa[x]);
            dist[x]+=dist[fa[x]];
            fa[x]=root;
        }
        return fa[x];
    }

    void merge(int x,int y) //将y放到x下
    {
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            fa[x]=y;
            dist[x]=len[y];
            len[y]+=len[x];
        }
    }
    int size(int x)
    {
        int t=find(x);
        return dist[x];
    }
};

int main()
{
    int p;
    cin>>p;
    DSU dsu(30000);
    while(p--)
    {
        char c;
        cin>>c;
        if(c=='M')
        {
            int x,y;
            cin>>x>>y;
            dsu.merge(x,y);
        }
        else 
        {
            int x,y;
            cin>>x>>y;
            if(dsu.find(x)==dsu.find(y))
            {
                cout<<abs(dsu.size(x)-dsu.size(y))-1<<'\n';
            }
            else cout<<"-1\n";
        }
    }
}
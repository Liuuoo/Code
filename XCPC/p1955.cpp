#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
// vector<int> fa0(N);
vector<int> fa1(N);

struct Node 
{
    int i,j;
    int e;    
};


bool cmp(Node i,Node j)
{
    return i.e>j.e;
}

struct UF
{
    vector<int> fa;
    UF(int n)
    {
        fa.resize(n+1);
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    int find(int x)
    {
        if(fa[x]==x) return x;
        else return fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            fa[x]=y;
        }
    }
};

struct Dis
{
    vector<int>a;
    Dis(vector<int>_a)
    {
        a=_a;
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
    }
    int find(int x)
    {
        return lower_bound(a.begin(),a.end(),x)-a.begin();
    }
    int size()
    {
        return a.size();
    }
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<Node> vec;
        vector<int>tmp;
        while(n--)
        {
            int i,j,e;
            cin>>i>>j>>e;
            vec.push_back({i,j,e});
            tmp.push_back(i);
            tmp.push_back(j);
        }
        Dis dis(tmp);
        for(int i=0;i<dis.size();i++)  
        {
            fa1[i]=i;
        }
        sort(vec.begin(),vec.end(),cmp);
        bool flag=false;
        UF uf(dis.size());
        for(int i=0;i<vec.size();i++)
        {
            int f=vec[i].i;
            int s=vec[i].j;
            int e=vec[i].e;
            f=dis.find(f);
            s=dis.find(s);
            if(e==1)
            {
                uf.merge(f,s);
            }
            else
            {
                if(uf.find(f)==uf.find(s))
                {
                    cout<<"NO\n";
                    flag=true;
                    break;
                }
            }
        }
        if(!flag) cout<<"YES\n";
    }
}
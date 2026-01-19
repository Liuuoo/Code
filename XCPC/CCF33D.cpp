#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N];
int c,m,n;
bool vaild(int x) {return (x>=1&&x<=c);}
struct Node
{
    int idx;
    int st;
};
pair<int,int> find(int p)
{
    int l=-1,r=-1;
    for(int i=p-1;i>=1;i--) 
    {
        if(a[i]) 
        {
            l=i;
            break;
        }
    }
    for(int i=p+1;i<=c;i++) 
    {
        if(a[i]) 
        {
            r=i;
            break;
        }
    }
    return {l,r};
}
bool cmp(const Node &i,const Node &j)
{
    if(i.st!=j.st) return i.st>j.st;
    else return i.idx>j.idx;
}
int main()
{

    cin>>c>>m>>n;

    for(int i=1;i<=m;i++)
    {
        int x,w;
        cin>>x>>w;
        a[x]=w;
    }

    while(n--)
    {
        int p;
        cin>>p;
        a[p]++;
        if(a[p]==5)
        {
            a[p]=0;
            priority_queue<Node,vector<Node>,decltype(&cmp)>q(cmp);
            pair<int,int>tmp=find(p);
            if(vaild(tmp.first)) 
            {
                a[tmp.first]++;
                if(a[tmp.first]>=5)
                {
                    q.push({tmp.first,0});
                }
            }
            if(vaild(tmp.second))
            {
                a[tmp.second]++;
                if(a[tmp.second]>=5) q.push({tmp.second,0});
            } 
            while(!q.empty())
            {
                auto f=q.top();
                q.pop();
                if(a[f.idx]==0) continue;
                a[f.idx]=0;
                pair<int,int>tmp=find(f.idx);
                if(vaild(tmp.first)) 
                {
                    a[tmp.first]++;
                    if(a[tmp.first]>=5)
                    {
                        q.push({tmp.first,f.st+1});
                    }
                }
                if(vaild(tmp.second))
                {
                    a[tmp.second]++;
                    if(a[tmp.second]>=5)
                    {
                        q.push({tmp.second,f.st+1});
                    }
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=c;i++) if(a[i]) cnt++;
        cout<<cnt<<'\n';
    }
}
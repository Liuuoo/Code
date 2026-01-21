#include<bits/stdc++.h>
using namespace std;
const int N=1234;
int n,m,v;
int b[N],c[N];
int ans=INT_MAX;
int suf[N];
struct Node 
{
    int a,t;
}arr[N];
bool cmp(Node &i,Node &j)
{
    return i.a>j.a;
}
map<int,int>M;
void dfs(int x,int s,int j)
{
    if(s+suf[x]<v) return;
    if(j>=ans) return;
    if(s>v) ans=min(ans,j);
    if(x==m)
    {
        return;
    }
    Node tt=arr[x];
    M[tt.t]++;
    int t=0;
    if(M[tt.t]==1) t+=b[tt.t]+c[tt.t];
    else t+=c[tt.t];
    dfs(x+1,s+tt.a,j+t);
    M[tt.t]--;
    dfs(x+1,s,j);
}

int main()
{
    cin>>n>>m>>v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        b[i]=x,c[i]=y;
    }

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        M[y]=0;
        arr[i]={x,y};
    }
    sort(arr,arr+m,cmp);
    for(int i=m-1;i>=0;i--)
    {
        suf[i]+=(suf[i+1]+arr[i].a);
    }
    dfs(0,0,0);
    cout<<ans;
}
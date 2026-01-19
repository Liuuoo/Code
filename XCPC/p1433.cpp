#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>vec;
int n;
double ans=(double)INT64_MAX;
int a[17];
bool vis[17];

double calc(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void dfs(int x)
{
    if(x==n)
    {
        double sum=0;
        int ix=0,iy=0;
        for(int i=0;i<n;i++) 
        {
            //cout<<a[i]<<" ";cout<<'\n';
            sum+=calc(ix,iy,vec[a[i]].first,vec[a[i]].second);
            ix=vec[a[i]].first;
            iy=vec[a[i]].second;
        }
        ans=min(ans,sum);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            a[x]=i;
            vis[i]=true;
            dfs(x+1);
            vis[i]=false;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    dfs(0);

    printf("%.2lf",ans);
}
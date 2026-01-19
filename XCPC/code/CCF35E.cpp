#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node 
{
    int c;
    int idx;
};
Node a[N];
int n,m,k;
pair<int,int>calc(int x)
{
    vector<int>vec;
    map<int,bool> vis;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int idx=a[i].idx;
        if(idx==x)
        {
            vec.push_back(a[i].c);
            if(vis.find(a[i].c)==vis.end()) cnt++;
            vis[a[i].c]=true;
        }
    }
    if(vec.size()==0) return {0,0};
    int i=0;
    int cl=0;
    while(1)
    {
        if(i>=vec.size()) break;
        cl++;
        while(vec[i]==vec[i+1]&&i+1<vec.size())
        {
            i++;
        }
        i++;
    }
    return {cnt,cl};
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]={x,1};
    }
    for(int i=1;i<=k;i++)
    {
        int x,l,r;
        cin>>x>>l>>r;
        for(int j=l;j<=r;j++)
        {
            if(a[j].idx==x) a[j].idx=i+1;
        }
        pair<int,int>ans=calc(i+1);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
}
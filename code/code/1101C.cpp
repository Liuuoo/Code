#include<bits/stdc++.h>
using namespace std; 
#define int long long

struct Node
{
    int l,r;
    int idx;
};
bool cmp(const Node &a, const Node &b)
{
    if(a.l!=b.l) return a.l<b.l;
    else if(a.r!=b.r) return a.r>b.r;
    else return a.idx<b.idx;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> vec;
    vec.push_back(0);
    int ans[n+1];
    Node a[n+1];
    int pre_max[n+1];
    pre_max[0]=0;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        a[i]={l,r,i};
        
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) 
    {
        vec.push_back(a[i].l);
        pre_max[i]=max(pre_max[i-1],a[i].r);
    }
    int p=0,i;
    for(i=1;i<n;i++)
    {
        int x=a[i].r;
        int y=a[i+1].l;
        if(y>pre_max[i]) 
        {
            p=i;
        }
    }
    if(p==0) 
    {
        cout<<-1<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(i<=p) ans[a[i].idx]=1;
        else ans[a[i].idx]=2;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
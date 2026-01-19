#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Node
{
    int t,r;
};

bool cmp(Node &i,Node&j)
{
    if(i.r!=j.r) return i.r>j.r;
    else return i.t>j.t;
}

signed main()
{
    int n;
    cin>>n;
    vector<Node> vec;
    int a[n+1],b[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
    {
        vec.push_back({a[i],b[i]});
    }
    sort(vec.begin(),vec.end(),cmp);

    vector<int>ans(n+1,0);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int t=vec[i].t;
        int r=vec[i].r;
        while(ans[t]!=0)
        {
            t--;
            if(t==0) break;
        }
        if(t!=0) 
        {
            ans[t]=1;
            sum+=r;
        }
    }
    cout<<sum;
}
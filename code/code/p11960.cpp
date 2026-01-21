#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int a,b;
    int del;
};
vector<Node> vec;

bool cmp(Node &i,Node &j)
{
    return i.del>j.del;
}

signed main()
{
    int n;
    cin>>n;
    int a[2*n+1],b[2*n+1];
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<2*n;i++)
    {
        int x;
        cin>>x;
        int del=a[i]-x;
        vec.push_back({a[i],x,del});
    }
    sort(vec.begin(),vec.end(),cmp);
    int sum=0;
    for(int i=0;i<2*n;i++)
    {
        if(i<n) sum+=vec[i].a;
        else sum+=vec[i].b;
    }
    cout<<sum;
}

#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[300];
// set<multiset<int>> ans;
int ans=0;
void dfs(int x,int ts)
{
    if(x==k)
    {
        // multiset<int> S;
        // int sum=0;
        // for(int i=0;i<x;i++)
        // {
        //     sum+=a[i];
        //     S.insert(a[i]);
        // }
        // if(sum>=n) return;
        // int las=n-sum;
        // S.insert(las);
        // ans.insert(S);
        // return;
        if(ts==n) ans++;
        return;
    }
    if(ts>=n) return;
    int b;
    if(x==0) b=1;
    else b=a[x-1];
    for(int i=b;i<=n-ts;i++)
    {
        a[x]=i;
        dfs(x+1,ts+i);
    }
}

int main()
{
    cin>>n>>k;
    dfs(0,0);
    cout<<ans;
}
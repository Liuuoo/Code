#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int t,n;
vector<int> ans;
vector<int> dfs(int time,vector<int> arr)
{
    for(auto x:arr) cout<<x<<" "; cout<<'\n';
    if(time==t)
    {
        return arr;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            vector<int> tmp=arr;
            swap(tmp[i],tmp[j]);
            if(time%2==0) arr=min(arr,dfs(time+1,tmp));
            else arr=max(arr,dfs(time+1,tmp));
        }
    }
    return arr;
}

int main()
{

    cin>>t>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        vec.push_back(x);
        ans.push_back(INT_MAX);
    }
    ;
    for(auto x:dfs(0,vec)) cout<<x<<" ";
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,int> M;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        M[x]++;
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        M[x]++;
    }
    int ans=0;
    for(auto x:M)
    {
        if(x.second==2)
        {
            ans++;
        }
    }
    cout<<ans;
}

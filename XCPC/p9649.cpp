#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        v.push_back({l,r});
    }
    sort(v.begin(),v.end());
    
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
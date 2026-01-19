#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    map<int,int>M;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        M[x]++;
    }
    for(auto x:M)
    {
        if(x.second>1)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO\n";
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
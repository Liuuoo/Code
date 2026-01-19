#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    set<int>S;
    while(n--)
    {
        int x;
        cin>>x;
        S.insert(x);
    }
    cout<<(S.size()-1)*2+1<<'\n';
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
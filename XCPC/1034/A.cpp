#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    n--;
    if(n%4==3) cout<<"Bob\n";
    if(n%4==2) cout<<"Alice\n";
    if(n%4==1) cout<<"Alice\n";
    if(n%4==0) cout<<"Alice\n";
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
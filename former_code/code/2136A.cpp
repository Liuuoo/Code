#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c<a||d<b)
    {
        cout<<"NO\n";
        return;
    }
    else 
    {
        int n=2;
        for(int i=1;i<=min(a,b);i++)
        {
            n+=2;
        }
        if(n<max(a,b)) 
        {
            cout<<"NO\n";
            return;
        }
        int e=c-a,f=d-b;
        n=2;
        for(int i=1;i<=min(e,f);i++)
        {
            n+=2;
        }
        if(n<max(e,f))
        {
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
    }
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
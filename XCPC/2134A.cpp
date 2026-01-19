#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(b%2==n%2&&a%2==n%2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        if(b%2!=n%2)
        {
            cout<<"NO"<<endl;
        }
        else 
        {
            if(a<b)
            {
                cout<<"YES"<<endl;
            }
            else 
            {
                cout<<"NO"<<endl;
            }
        }
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
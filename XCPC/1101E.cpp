#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int lmax=0,rmax=0;
    while(n--)
    {
        char c; int a,b;
        cin>>c>>a>>b;
        if(a>b) swap(a,b);
        if(c=='+')
        {
            lmax=max(lmax,a);
            rmax=max(rmax,b);
        }
        else 
        {
            if(a<lmax||b<rmax)
            {
                cout<<"NO\n";
            }
            else cout<<"YES\n";
        }
    }
}
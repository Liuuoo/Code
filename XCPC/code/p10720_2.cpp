#include<bits/stdc++.h>
using namespace std;
#define int long long

bool jud(int x)
{
    set<int>S;
    for(int i=2;i<=x/i;i++)
    {
        while(x%i==0)
        {
            S.insert(i);
            x/=i;
        }
    }
    if(x>=2) S.insert(x);
    return (S.size()==2);
}

signed main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        if(jud(x)) cout<<"1\n";
        else cout<<"0\n";
    }
}
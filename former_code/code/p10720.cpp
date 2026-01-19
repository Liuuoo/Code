#include<bits/stdc++.h>
using namespace std;

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
    if(x>1) S.insert(x);
    return (S.size()==2);
}

int main()
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
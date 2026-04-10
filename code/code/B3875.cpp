#include<bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
    if(x<=1) return false;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

bool jud(int x)
{
    while(x)
    {
        if(!isprime(x)) return false;
        x/=10; 
    }
    return true;
}

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=m;i<=n;i++)
    {
        if(jud(i))
        {
            cout<<i<<'\n';
        }
    }
}
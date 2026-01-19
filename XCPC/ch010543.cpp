#include<bits/stdc++.h>
using namespace std;

bool is_primer(int x)
{
    if(x==1) return false;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(is_primer(i)&&n%i==0&&is_primer(n/i))
        {
            cout<<n/i;
            return 0;
        }
    }
}
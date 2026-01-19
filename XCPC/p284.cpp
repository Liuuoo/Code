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
    for(int i=4;i<=n;i+=2)
    {
        for(int j=2;j<=i/2;j++)
        {
            if(is_primer(j)&&is_primer(i-j))
            {
                cout<<i<<"="<<j<<"+"<<i-j<<'\n';
                break;
            }
        }
    }
}
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
    int sum=0;
    int m=1;
    int d=1;
    for(int i=1;i<=n;i++)
    {
        sum+=m;
        d--;
        if(d==0)
        {
            d=m+1;
            m++;
        }
    }
    cout<<sum;
}
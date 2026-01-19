#include<bits/stdc++.h>
using namespace std;

bool is_primer(int x)
{
    if(x==1) return true;
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
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(is_primer(i)) cnt++;
    }
    cout<<cnt;
}
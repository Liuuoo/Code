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
    int a,b;
    cin>>a>>b;
    int cnt=0;
    for(int i=a;i<=b;i++)
    {
        if(is_primer(i)) cnt++;
    }
    cout<<cnt;
}
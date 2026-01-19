#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    map<int,int>M;
    int n;
    cin>>n;
    int tmp=n;
    for(int i=2;i*i<=tmp;i++)
    {
        while(n%i==0)
        {
            M[i]++;
            n/=i;
        }
    }
    if(n>1) M[n]++;
    bool f=false;
    for(auto x:M)
    {   
        if(f) cout<<" * ";
        cout<<x.first;
        if(x.second>1) cout<<"^"<<x.second;
        f=true; 
    }
}
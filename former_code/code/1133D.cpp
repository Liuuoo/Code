#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    map<pair<int,int>,int> M;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int s=b[i];
        int m=a[i];
        if(m==0) 
        {
            if(s==0) ans++;
            continue;
        }
        // else if(s==0) 
        // {
        //     s=0;
        //     m=0;
        // }
        // else 
        // {
            int g=__gcd(s,m);
            s/=g;
            m/=g;
        // }
        M[{s,m}]++;
    }
    int ext=0;
    for(auto x:M)
    {
        ext=max(ext,x.second);
    }
}
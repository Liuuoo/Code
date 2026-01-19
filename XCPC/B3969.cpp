#include<bits/stdc++.h>
using namespace std;

bool jud(int x,int k)
{
    int maxn=0;
    for(int i=2;i<=x/i;i++)
    {
        while(x%i==0)
        {
            x/=i;
            maxn=max(maxn,i);
        }
    }
    if(x>1) maxn=max(maxn,x);
    return (maxn<=k);
}

int main()
{
    int n,b;
    cin>>n>>b;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(jud(i,b)) cnt++;
    }
    cout<<cnt;
}
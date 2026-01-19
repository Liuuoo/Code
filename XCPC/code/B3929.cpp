#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6+10;
bool isprime[N];
set<int> S;

void sieve(int x,int n)
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(i*i>=x)
        {
            for(int j=i*i;j<=n;j+=i*i)
            {
                S.insert(j);
            }
        }
    }
}

signed main()
{
    int a,n;
    cin>>a>>n;
    sieve(a,N);
    while(n--)
    {
        int x;
        cin>>x;
        if(a==1) {
            cout<<"lucky\n";
        }
        else if(S.find(x)!=S.end())
        {
            cout<<"lucky\n";
        }
        else 
        {
            int i=1;
            while(S.find(x+i)==S.end())
            {
                i++;
            }
            cout<<x+i<<'\n';
        }
    }
}
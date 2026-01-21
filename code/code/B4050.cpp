#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
bool isprimer[N+10];
set<int>primer;
void sieve(int n)
{
    memset(isprimer,true,sizeof(isprimer));
    isprimer[0]=isprimer[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(isprimer[i])
        {
            primer.insert(i);
            for(int j=i*i;j<=n;j+=i)
            {
                isprimer[j]=false;
            }
        }
    }
}

int calc(int x)
{
    int i=0;
    while(x>0)
    {
        int tmp=pow(2,i);
        i++;
        x-=tmp;
    }
    if(x==0) return i;
    else return INT_MAX;
}

signed main()
{
    sieve(N);
    primer.insert(0);
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        int cnt=INT_MAX;
        for(auto x:primer)
        {
            if(x>a) break;
            int tmp=(x!=0);
            cnt=min(cnt,tmp+calc(a-x));
        }
        if(cnt==INT_MAX) cnt=-1;
        cout<<cnt<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> tree;
struct BIT
{
    int sz;
    BIT(int n)
    {
        tree.resize(n+10); 
        sz=n;
    }
    int low_bit(int x)
    {
        return (x&(-x));
    }
    void add(int n,int x)
    {
        while(n<=sz)
        {
            tree[n]+=x;
            n+=low_bit(n);
        }
    }
    int sum(int n)
    {
        int res=0;
        while(n>0)
        {
            res+=tree[n];
            n-=low_bit(n);
        }
        return res;
    }
};


signed main()
{
    int n,m;
    cin>>n>>m;
    BIT bit(n);
    int a[n+1];
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        a[i]=x;
    }
    while(m--)
    {
        int q,x;
        cin>>q>>x;
        if(q==1)
        {
            int y,k; 
            cin>>y>>k;
            bit.add(x,k);
            bit.add(y+1,-k);
        }
        else 
        {
            int sum2=bit.sum(x);
            int sum1=bit.sum(x-1);
            cout<<sum2-sum1+a[x]<<'\n';
        }
    }
}
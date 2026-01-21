#include<bits/stdc++.h>
using namespace std;
#define int long long
struct BIT
{
    vector<int>tree;
    int sz;
    BIT(int n)
    {
        sz=n;
        tree.resize(n+1);
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
    int pre_sum[n+1];
    pre_sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        pre_sum[i]=pre_sum[i-1]+x;
    }
    BIT t1(n+2),t2(n+2);
    while(m--)
    {
        int j;
        cin>>j;
        if(j==1)
        {
            int x,y,k;
            cin>>x>>y>>k;

            t1.add(x,k);
            t1.add(y+1,-k);

            t2.add(x,k*(x-1));
            t2.add(y+1,-k*(y));
        }
        else 
        {
            int x,y;
            cin>>x>>y;
            cout<<pre_sum[y]-pre_sum[x-1]+y*t1.sum(y)-t2.sum(y)-(x-1)*t1.sum(x-1)+t2.sum(x-1)<<'\n';
        }
    }
}
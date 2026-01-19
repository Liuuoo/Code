#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

bool vis[N];

int low_bit(int x) 
{
    return (x&(-x));
}
struct BIT
{
    vector<int> tree;
    int sz;
    BIT(int n)
    {
        tree.resize(n+10);
        sz=n;
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

bool visl[N],visr[N];

int main()
{
    int n;
    cin>>n;
    int sz=0;
    int a[n+1];
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        if(!vis[a[i]]) sz++;
        vis[a[i]]=true;
    }
    BIT rt(n),lt(n);
    int l_sum[n+1],r_sum[n+1];
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        if(visl[x]) l_sum[i]=0;
        else l_sum[i]=1;
        visl[x]=true;
    }
    for(int i=n-1;i>=0;i--)
    {
        int x=a[i];
        if(visr[x]) r_sum[i]=0;
        else r_sum[i]=1;
        visr[x]=true;
    }
    int L[n+1],R[n+1];
    L[0]=0;
    R[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        L[i]=L[i-1]+l_sum[i-1];
    }
    for(int i=n;i>0;i--) 
    {
        R[i]=R[i+1]+r_sum[i-1];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sz-L[l-1]-R[r+1]<<'\n';
    }
}
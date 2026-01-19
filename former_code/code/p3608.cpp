#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
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

int find(int x,vector<int> &vec)
{
    return (lower_bound(vec.begin(),vec.end(),x,greater<>())-vec.begin());
}

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    vector<int> vec;
    vec.push_back(INT_MAX);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        vec.push_back(a[i]);
    }
    unique(vec.begin(),vec.end());
    sort(vec.begin(),vec.end(),greater<>());
    int L[n+1],R[n+1];
    BIT bitl(n),bitr(n);
    for(int i=0;i<n;i++)
    {
        int idx=find(a[i],vec);
        bitl.add(idx,1);
        L[i]=bitl.sum(idx-1);

        int idx2=find(a[n-i-1],vec);
        bitr.add(idx2,1);
        R[n-i-1]=bitr.sum(idx2-1);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(2*min(L[i],R[i])<max(L[i],R[i]))
        {
            ans++;
        }
    }
    cout<<ans;
}
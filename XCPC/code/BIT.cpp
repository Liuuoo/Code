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
        return x&(-x);
    }
    void add(int n,int x)
    {
        while(n)
        {
            tree[n]+=x;
            n-=low_bit(n);
        }
    }
    int sum(int n)
    {
        int res=0;
        while(n<=sz)
        {
            res+=tree[n];
            n+=low_bit(n);
        }
        return res;
    }
};
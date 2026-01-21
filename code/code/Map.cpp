#include<bits/stdc++.h>
using namespace std;
struct Map
{
    map<int,int>S;
    int sz;
    Map()
    {
        sz=0;
    }
    void insert(int x)
    {
        sz++;
        S[x]++;
    }
    void erase(int x)
    {
        sz--;
        S[x]--;
        if(S[x]==0)
        {
            S.erase(x);
        }
    }
    int max()
    {
        if(sz==0)
        {
            return -1;
        }
        return S.begin()->first;
    }
    int min()
    {
        if(sz==0) return -1;
        return S.rbegin()->first;
    }
};
#include<bits/stdc++.h>
using namespace std;
int n;
vector<set<int>> vec(5010);
int a[5010];
int m_gcd;
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
        if(sz==0)
        {
            return -1;
        }
        return S.rbegin()->first;
    }
    int count(int x)
    {
        return S[x];
    }
};

bool jud(int x)
{
    if(x==0) return false;
    Map m;
    int i=0,j=0;
    while(j<n)
    {
        if(j-i<x)
        {
            for(auto it:vec[a[j]])
            {
                m.insert(it);
            }
            j++;
        }
        else
        {
            for(auto it:vec[a[i]])
            {
                m.erase(it);
            }
            i++;
        }
        if(m.count(m_gcd)) return true; 
    }
    return false;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    m_gcd=a[0];
    int ans=n+1;
    for(int i=1;i<n;i++)
    {
        m_gcd=__gcd(m_gcd,a[i]);
    }
    int L=0,R=n;
    while(L<=R)
    {
        int M=(L+R)>>1;
        if(jud(M)) R=M;
        else L=M+1;
    }
    cout<<L<<"\n";
}

int main()
{
    for(int i=1;i<=5000;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                vec[i].insert(j);
                vec[i].insert(i%j);
            }
        }
    }
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
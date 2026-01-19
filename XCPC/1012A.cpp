#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Map{
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
        if(sz==0) return -1;
        else return S.begin()->first;
    }
    int min()
    {
        if(sz==0) return-1;
        else return S.rbegin()->first;
    }
};

Map m1;
Map m2;

signed main()
{
    int n;
    cin>>n;
    int ans=INT64_MAX;
    int a[2*n+1];
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
        m2.insert(a[i]);
    }
    sort(a,a+2*n);
    int j=0;
    int i=0;
    while(1)
    {
        if(j-i<n)
        {
            m1.insert(a[j]);
            m2.erase(a[j]);
            j++;
        }
        else 
        {
            ans = min(ans, (m1.max()-m1.min())*(m2.max()-m2.min()));
            m1.erase(a[i]);
            m2.insert(a[i]);
            m1.insert(a[j]);
            m2.erase(a[j]);
            i++;
            j++;
        }
        if(j==2*n) break;
    }
    cout<<ans;
}

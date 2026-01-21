#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> del;
int a[200010+10];
bool jud(int x)
{
    int tmp=0;
    
    for(int i=0;i<del.size();i++)
    {
       tmp+=(del[i]-1)/x;
        if(tmp>m+1) return false;
    }
    return true;
}

signed main()
{
 
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        del.push_back(a[i]-a[i-1]);
    }
    sort(del.begin(),del.end());
    int l=1,r=del.back();
    while(l<r)
    {
        int m=(l+r)/2;
        //cout<<l<<" "<<r<<" "<<m<<'\n';
        if(jud(m)) r=m;
        else l=m+1;
    }
    cout<<l;
}
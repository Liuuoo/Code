#include<bits/stdc++.h>
using namespace std;
int a[55],b[1111];
bool visb[1111];
int n,m;
int ans=0;
int A[55];
bool dfs(int x)
{
    if(x == 1)
    {
        for(int i = 1; i <= n; i++) if(A[i] >= b[1]) return 1;
        return 0;
    } 
    for(int i=m;i>=1;i--)
    {
        if(A[i]>=b[x])
        {
            A[i]-=b[x];
            if(A[i] < b[1]) if(dfs(x-1)) return 1;
            A[i]+=b[x];
        }
        dfs(x-1);
    }
    return 0;
}

bool jud(int x) //能否放入x个小木板
{
    for(int i=1;i<=m;i++) A[i]=a[i]; 
    return dfs(x);
}

int main()
{
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    // cout<<jud(8);
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(jud(mid)) 
        {
            l=mid;
        }
        else r=mid-1;
    }
    cout<<l;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[n+1];
    int more=m*k;
    int b[n+1];
    int sum=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1,greater<int>());
    multiset<int>S;
    for(int i=more+1;i<=n;i++)
    {
        S.insert(b[i]);
        sum-=b[i];
    }
    cout<<sum<<endl;
    int tmp=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(S.find(a[i])!=S.end())
        {
            S.erase(S.find(a[i]));
            continue;
        }
        else 
        {
            tmp++;
            if(tmp==m)
            {
                cnt++;
                if(cnt<k) cout<<i<<" ";
                tmp=0;
            }
        }
    }
}
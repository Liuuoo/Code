#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int x;
    int y;
    bool operator<(const Node other) const{
        if(x>other.x) return true;
        else if(x==other.x) return y>other.y;
        else  return false;
    }
};

void solve()
{
    int n,k;
    cin>>n>>k;
    Node a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i].x;
    for(int i=1;i<=n;i++) cin>>a[i].y;
    int sum=0;
    for(int i=1;i<=n;i++) 
    {
        if(a[i].y>a[i].x) swap(a[i].y,a[i].x);
        sum+=a[i].x-a[i].y;
    }
    sort(a+1,a+n+1);
    int mi=INT_MAX;
    for(int i=1;i<n;i++)
    {
        int aa[]={a[i].x,a[i+1].x,a[i].y,a[i+1].y};
        int ini=aa[0]+aa[1]-(aa[2]+aa[3]);
        sort(aa,aa+4,greater<int>());
        int nx=aa[0]+aa[1]-(aa[2]+aa[3]);
        mi=min(mi,(nx-ini));
    }
    if(mi<=0) cout<<sum<<"\n";
    else 
    {
        cout<<sum+mi<<'\n';
    }
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}







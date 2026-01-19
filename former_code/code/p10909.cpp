#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> vec;

bool jud(int x)
{
    int sum=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]<=x) continue;
        int tmp=vec[i];
        sum+=(tmp)/x;
        if(tmp%2==0)sum--;
        if(sum>m+1) {
            // cout<<sum<<'\n';
            return false;
        }
    }
    // cout<<sum<<'\n';
    return true;
}

signed main() 
{
    cin>>n>>m;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        // vec.push_back(x);
    }
    for(int i=1;i<n;i++)
    {
        vec.push_back(a[i]-a[i-1]);
    }

    sort(vec.begin(),vec.end());

    int l=1,r=vec.back();
    while(l<r)
    {
        int mid=(l+r)/2;
        // cout<<mid<<' ';
        if(jud(mid)) r=mid;
        else l=mid+1;
        
        //cout<<l<<" "<<r<<" "<<mid<<'\n';
    }
    cout<<l;
}

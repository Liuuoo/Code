#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool vis[N];
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) vis[i]=false;
    int a[n+1];
    int b[n+1];
    int c;
    for(int i=1;i<=n/2;i++) cin>>a[i];
    if(n%2!=0) cin>>c;
    for(int i=1;i<=n/2;i++) cin>>b[i];
    reverse(b+1,b+(n/2+1));
    map<int,int> M1,M2;
    M1.clear();
    M2.clear();
    for(int i=1;i<=n/2;i++)
    {
        if(a[i]==b[i])
        {
            vis[i]=true;
            continue;
        }
        M1[a[i]]++;
        M1[b[i]]++;
    }
    int maxCnt1=0;
    int maxVal1=INT_MIN;
    for(auto x:M1)
    {
        if(x.second>maxCnt1)
        {
            maxCnt1=x.second;
            maxVal1=x.first;
        }
    }
    for(int i=1;i<=n/2;i++)
    {
        if(!vis[i]&&a[i]!=maxVal1&&b[i]!=maxVal1)
        {
            M2[a[i]]++;
            M2[b[i]]++;
        }
    }
    int maxCnt2=0;
    int maxVal2=INT_MIN;
    for(auto x:M2)
    {
        if(x.second>maxCnt2)
        {
            maxCnt2=x.second;
            maxVal2=x.first;
        }
    }
    for(int i=1;i<=n/2;i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i]==maxVal1||a[i]==maxVal2||b[i]==maxVal1||b[i]==maxVal2)
            {
                ans+=1;
            }
            else ans+=2;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
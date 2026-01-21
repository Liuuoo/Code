#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int i=1;
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        int cnt=0;
        while(j<=n&&a[j]==a[i])
        {
            cnt++;
            j++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
}
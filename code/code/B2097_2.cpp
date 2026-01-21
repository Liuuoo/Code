#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    int i=1,j=1,cnt=0;
    while(i<=n)
    {
        j=i;
        cnt=0;
        while(j<=n&& a[j]+cnt==a[i] )
        {
            j++;
            cnt++;
        }
        ans=max(ans,cnt);
        i=j;
    }
    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int M[n+1];
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        M[x]=i;
    }
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if(M[i]+1!=M[i+1])
        {
            if(M[i]==n&&M[i+1]==1)
            {
                ans=max(ans,2);
            }
            else ans=max(ans,3);
        }
    }
    cout<<ans;
}
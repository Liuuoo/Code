#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int i=1,j=1;
    int ansi,ansj;
    int sum=0;
    int ans=INT_MIN;
    while(j<=n)
    {
        while(sum<=m&&j<=n)
        {
            sum+=a[j];
            if(sum<=m&&ans<sum)
            {
                ans=sum;
                ansi=i;
                ansj=j;
            }
            j++;
        }
        while(sum>m)
        {
            sum-=a[i];
            i++;
            if(sum<=m&&ans<sum)
            {
                ans=sum;
                ansi=i;
                ansj=j-1;
            }
        }
    }
    cout<<ansi<<" "<<ansj<<" "<<ans;
}

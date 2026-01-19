#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
signed main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    int i=0,j=0;
    int ans=0;
    int tmpa=0,tmpb=0;

    while(1)
    {
        if(i==n||j==m) break;
        tmpa=a[i];
        tmpb=b[j];
        //cout<<i<<" "<<j<<'\n';
        while(tmpa!=tmpb)
        {
            //cout<<tmpa<<" "<<tmpb<<'\n';
            if(tmpa<tmpb){
                i++;
                tmpa+=a[i];
            }
            else 
            {
                j++;
                tmpb+=b[j];
            }
            ans++;
        }
        i++;
        j++;
    }
    cout<<ans;
}
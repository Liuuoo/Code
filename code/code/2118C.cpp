#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define F first
#define S second
#define pb push_back
int a[400000];
signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int now=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            for(int j=0;j<62;j++)
            {
                int y=(1LL<<j);
                if((x&y)==0)
                {
                    a[cnt++]=y;
                }
                else now++;
            }
        }
        sort(a,a+cnt);
        int pos=0,sum=0;
        while(1)
        {
            if(sum+a[pos]>k) break;
            sum+=a[pos];
            pos++;
        }
        cout<<now+pos<<'\n';
    }

}



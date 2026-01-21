#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> pre_sum(n+1);
    vector<int>S;
    for(int i=1;i<=n;i++) 
    {
        pre_sum[i]+=pre_sum[i-1]+a[i];
        if(i!=n)
        {
            if(a[i]==a[i+1]) S.push_back(i);
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;

        if((r-l+1)%3!=0||(pre_sum[r]-pre_sum[l-1])%3!=0)
        {
            cout<<"-1\n";
        }
        else 
        {
            int nex=lower_bound(S.begin(),S.end(),l)-S.begin();
            if(S.empty()||nex>=(int)S.size()||S[nex]<l||S[nex]>r)
            {
                cout<<(r-l+1-3)/3+2<<'\n';
            }
            else
            {
                if(S[nex]==r)
                {
                    if(a[S[nex]]==a[S[nex]-1]) cout<<(r-l+1)/3<<'\n';
                    else cout<<(r-l+1-3)/3+2<<'\n';
                }
                else cout<<(r-l+1)/3<<'\n';
            }

        }
    }
    
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
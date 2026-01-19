#include<bits/stdc++.h>
using namespace std;

bool jud(vector<short> vec,vector<int> a)
{
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i]==-1)
        {
            return false;
        }
    }
    int n=vec.size()-1;
    vector<int> pre_sum(n+1),back_sum(n+2);
    pre_sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(vec[i]==0)
        {
            pre_sum[i]=pre_sum[i-1]+1;
        }
        else pre_sum[i]=pre_sum[i-1];
    }
    back_sum[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        if(vec[i]==1)
        {
            back_sum[i]=back_sum[i+1]+1;
        }
        else back_sum[i]=back_sum[i+1];
    }

    for(int i=1;i<=n;i++)
    {
        int cnt=pre_sum[i-1]+back_sum[i+1]+1;
        if(cnt!=a[i])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<short> vec1(n+1),vec2(n+1); // 0左 1右
    for(int i=1;i<=n;i++) cin>>a[i];
    vec1[1]=0;
    vec2[1]=1;
    // 0:a_i-1=0 a_i=1 / a_i-1=1 a_i-1=0
    // 1:a_i-1=0 a_i=0
    //-1:a_i-1=1 a_1=1
    for(int i=2;i<=n;i++)
    {
        int del=a[i]-a[i-1];
        if(del==0)
        {
            if(vec1[i-1]==0) vec1[i]=1;
            else vec1[i]=0;

            if(vec2[i-1]==0) vec2[i]=1;
            else vec2[i]=0;
        }
        else if(del==1)
        {
            if(vec1[i-1]==0) vec1[i]=0;
            else vec1[i]=-1;

            if(vec2[i-1]==0) vec2[i]=0;
            else vec2[i]=-1;

        }
        else if(del==-1)
        {
            if(vec1[i-1]==1) vec1[i]=1;
            else vec1[i]=-1;

            if(vec2[i-1]==1) vec2[i]=1;
            else vec2[i]=-1;
        }
        else 
        {
            cout<<"0\n";
            return;
        }
    }

    int ans=0;

    if(jud(vec1,a))
    {
        ans++;
    }

    if(jud(vec2,a))
    {
        ans++;
    }
    cout<<ans<<'\n';
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
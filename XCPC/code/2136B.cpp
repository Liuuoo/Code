#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<char>vec;
    for(int i=0;i<n;i++) 
    {
        char c;
        cin>>c;
        vec.push_back(c);
    }
    int i=0;
    int ans=0;
    while(i<n)
    {
        int j=i;
        int tmp=0;
        while(j<n&&vec[j]=='1')
        {
            tmp++;
            ans=max(ans,tmp);
            j++;
        }
        i=j;
        i++;
    }
    if(ans>=k)
    {
        cout<<"NO\n";
        return;
    }
    else 
    {
        int cnt=1;
        int res[n+1];
        for(int i=0;i<n;i++)
        {
            if(vec[i]=='1') res[i]=cnt++;
        }
        for(int i=0;i<n;i++)
        {
            if(vec[i]=='0') res[i]=cnt++;
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<'\n';
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
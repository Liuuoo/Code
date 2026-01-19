#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin>>n;
    vector<int> a,b;
    vector<int> c;
    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        string s;
        int x;
        cin>>s>>x;
        if(s=="11")
        {
            ans+=x;
            cnt++;
        }
        else if(s=="10")
        {
            a.push_back(x);
        }
        else if(s=="01")
        {
            b.push_back(x);
        }
        else 
        {
            c.push_back(x);
        }

    }
    sort(a.begin(),a.end(),greater<>());
    sort(b.begin(),b.end(),greater<>());
    sort(c.begin(),c.end(),greater<>());
    for(int i=0;i<min(a.size(),b.size());i++)
    {
        ans+=a[i];
        ans+=b[i];
    }

    for(int i=min(a.size(),b.size());i<max(a.size(),b.size());i++)
    {
        if(b.size()>a.size()) c.push_back(b[i]);
        else c.push_back(a[i]);
    }

    sort(c.begin(),c.end(),greater<>());

    for(int i=0;i<min(cnt,(int)c.size());i++)
    {
        ans+=c[i];
    }

    cout<<ans;
}
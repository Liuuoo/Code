#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    
    vector<int>odd_sum;
    vector<int>even_sum;
    vector<int>vec;
    odd_sum.push_back(0);
    even_sum.push_back(0);
    vec.push_back(0);

    vec.push_back(a[0]);

    for(int i=1;i<n;i++)
    {
        vec.push_back(a[i]-a[i-1]);
    }
    vec.push_back(m-a[n-1]);

    for(int i=0;i<vec.size();i++)
    {
        if(i%2==0)
        {
            int tmp=even_sum.back();
            even_sum.push_back(tmp+vec[i]);
            
            odd_sum.push_back(odd_sum.back());
        }
        else 
        {
            int tmp=odd_sum.back();
            odd_sum.push_back(tmp+vec[i]);

            even_sum.push_back(even_sum.back());
        }
    }

    // for(auto x:odd_sum) cout<<x<<' ';
    // cout<<"\n";
    // for(auto x:even_sum) cout<<x<<" ";
    // cout<<"\n";

    int ans=INT64_MIN;
    for(int i=2;i<odd_sum.size();i++)
    {
        if(i%2==0)
        {
            if(odd_sum[i]-odd_sum[i-1]==1) continue;
            int tmp=odd_sum[i]-1;
            tmp+=(even_sum.back()-even_sum[i-1]);
            ans=max(ans,tmp);
        }
        else 
        {
            if(even_sum[i]-even_sum[i-1]==1) continue;
            int tmp=odd_sum[i];
            tmp+=(even_sum.back()-even_sum[i-1]-1);
            ans=max(ans,tmp);
        }
    }
    cout<<max(ans,odd_sum.back());
}
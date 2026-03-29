#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
long long ans=0;

void _merge(int l,int mid,int r)
{
    vector<int>tmp;
    int i=l,j=mid+1,t=0;
    while(i<=mid&&j<=r)
    {
        if(vec[i]>vec[j]) 
            tmp.push_back(vec[i++]);
        else 
        {
            tmp.push_back(vec[j++]);
            ans+=mid-i+1;
        }
    }
    while(i<=mid) tmp.push_back(vec[i++]);
    while(j<=r) tmp.push_back(vec[j++]);
    for(int i=l;i<=r;i++) vec[i]=tmp[t++];
}

void merge_sort(int l,int r)
{
    if(l==r) return;
    int mid=l+(r-l)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r); //右侧从mid+1开始
    _merge(l,mid,r);
}

signed main()
{
    int n;
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    merge_sort(0,n-1);
    // for(auto x:vec) cout<<x<<" ";
    cout<<ans;
}
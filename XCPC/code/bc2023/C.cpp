#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
map<int,int> mp;


signed main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    int cnt1=0;
    int cntd2=0;
    for(auto x: mp)
    {
        if(x.second==1) cnt1++;
        if(x.second>2) cntd2+=x.second-2;
    }
    int del=cntd2-cnt1;
    if(del>0)
    {
        cout<<cntd2;
    }
    else {
        cout<<cntd2+(cnt1-cntd2)/2;
    }
}
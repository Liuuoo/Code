#include<bits/stdc++.h>
using namespace std;
vector<long long>fi;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>ans;
    while(m--)
    {
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        // cout<<fi[n-1]<<"\n";
        if(a[0]>=fi[n-1]&&a[1]>=fi[n-1]&&a[2]>=fi[n-1]+fi[n-2])
            ans.push_back(1);
        else 
            ans.push_back(0);
    }
    for(auto x:ans) cout<<x; cout<<'\n';
}

int main()
{
    fi.push_back(1);
    fi.push_back(2);
    for(int i=2;i<=10;i++)
    {
        fi.push_back(fi[i-1]+fi[i-2]);
    }
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
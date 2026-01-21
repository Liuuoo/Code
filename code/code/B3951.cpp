#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    int ans=0;
    vector<int>vec;
    while(m--)
    {
        int x;
        cin>>x;
        bool flag=false;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]>a[x])
            {
                cout<<vec.size()-i<<'\n';
                flag=true;
                break;
            }  
        }
        if(!flag) cout<<"0\n";
        vec.push_back(a[x]);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end()); 
    }
}
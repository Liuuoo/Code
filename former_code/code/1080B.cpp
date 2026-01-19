#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>M;

bool jud(int n)
{
    for(auto x:M)
    {
        if(x.second%(n-x.first)!=0) return false;
    }
    return true;
}

signed main()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        M[x]++;
    }
    vector<int>vec(n+10,0);
    vector<int>tim(n+10,0);
    vector<bool>vis(n+10,false);
    if(jud(n))
    {   
        int cnt=1;
        cout<<"Possible\n";
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            if(tim[x]==(n-x)||vec[x]==0)
            {
                while(vis[cnt]==true) cnt++;
                cout<<cnt<<" ";
                vis[cnt]=true;
                vec[x]=cnt;
                tim[x]=0;
                tim[x]++;
            }
            else 
            {
                cout<<vec[x]<<" ";
                tim[x]++;
            }
        }
    }
    else 
    {
        cout<<"Impossible\n";
    }
}
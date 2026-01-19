#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,set<pair<int,int>>>m1;
vector<vector<int>> ans;

int main()
{

    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            m1[{(i|j),(i&j)}].insert({i,j});
        }
    }
    int n; cin>>n;
    int a[n+1],b[n];
    for(int i=0;i<n-1;i++) cin>>a[i];
    for(int i=0;i<n-1;i++) cin>>b[i];

    for(auto x:m1[{a[0],b[0]}])
    {
        ans.push_back({x.first,x.second});
    }

    for(int i=1;i<n-1;i++)
    {
        auto x=m1[{a[i],b[i]}];
        int ln=ans.size();
        for(int j=0;j<ln;j++)
        {
            bool jud=false;
            if(ans[j][0]==-1) continue;
            else 
            {
                for(auto it:x)
                {
                    if(it.first==ans[j].back())
                    {
                        ans[j].push_back(it.second);
                        jud=true;
                        break;
                    }
                }
            }
            if(!jud) ans[j][0]=-1;
        }
    }
    int t=-1;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i][0]!=-1)
        {
            t=i;
            break;
        }
    }
    if(t==-1) cout<<"NO\n";
    else 
    {
        cout<<"YES\n";
        for(int i=0;i<ans[t].size();i++)
        {
            cout<<ans[t][i]<<" ";
        }
    }
}
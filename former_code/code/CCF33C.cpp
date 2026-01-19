#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<vector<pair<int,int>>>vec;
    vector<string>ss(n+1);
    map<string,int>cnt[n+1];
    set<string>dist;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        ss[i]=s;
        int j=0;
        while(j<s.size())
        {
            string e,d;
            while(j<s.size()&&isalpha(s[j]))
            {
                e+=s[j];
                j++;
            }
            while(j<s.size()&&isdigit(s[j]))
            {
                d+=s[j];
                j++;
            }
            cnt[i][e]+=stoi(d);
            dist.insert(e);
        }
    }
    vec.resize(dist.size()+1);
    int p=1;
    for(auto x:dist)
    {
        vec[p++].resize(n+1);
    }
    for(int i=1;i<=n;i++)
    {
        int p=1;
        for(auto x:dist)
        {
            vec[p++][i]={cnt[i][x],1};
        }
    }
    // for(int i=1;i<=dist.size();i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<vec[i][j].first<<"/"<<vec[i][j].second<<" ";
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
    for(int i=1;i<=min(n,(int)dist.size());i++)
    {
        if(vec[i][i].first==0)
        {
            for(int j=i+1;j<=(int)dist.size();j++)
            {
                if(vec[j][i].first!=0)
                {
                    swap(vec[i],vec[j]);
                }
            }
        }
        auto num=vec[i][i];
        if(num.first==0) continue;
        // swap(num.first,num.second);
        for(int j=i+1;j<=dist.size();j++) //往下的所有行
        {
            if(vec[j][i].first==0) continue;
            auto num2=vec[j][i];
            vec[j][i]={0,1};
            swap(num2.first,num2.second);
            for(int k=i+1;k<=n;k++)
            {
                int son=vec[j][k].first* num.first * num2.first;
                int mon=vec[j][k].second* num.second * num2.second;

                int ns=son*vec[i][k].second-vec[i][k].first*mon;
                int nm=mon*vec[i][k].second;
                int g=__gcd(ns,nm);
                ns=ns/g;
                nm=nm/g;
                // if(mon>=vec[i][k].second)
                // {
                //     if(mon==vec[i][k].second)
                //     {
                //         if(son<vec[i][k].first)
                //         {
                //             ns*=-1;
                //         }
                //     }
                //     else ns*=-1;
                // }
                vec[j][k]={ns,nm};
            }
        }
        // for(int i=1;i<=dist.size();i++)
        // {
        //     for(int j=1;j<=n;j++)
        //     {
        //         cout<<vec[i][j].first<<"/"<<vec[i][j].second<<" ";
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n';
    }
    // for(int i=1;i<=dist.size();i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<vec[i][j].first<<"/"<<vec[i][j].second<<" ";
    //     }
    //     cout<<'\n';
    // }
    int las=0;
    for(int i=1;i<=dist.size();i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vec[i][j].first!=0) 
            {
                las++;
                break;
            }
        }
    }
    cout<<(las<n?'Y':'N')<<'\n';
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
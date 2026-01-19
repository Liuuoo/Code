#include<bits/stdc++.h>
using namespace std;
struct Node 
{
    string name;
    char p;
    int t;
    string pd;
};

bool cmp(Node &i,Node&j)
{
    if(i.name!=j.name) return i.name<j.name;
    else if(i.t!=j.t) return i.t<j.t;
    else if(i.p!=j.p) return i.p<j.p;
    else  return i.pd<j.pd;
}

void solve()
{
    int n;
    cin>>n;
    vector<Node> vec;
    for(int i=0;i<n;i++)
    {
        string a,pd;
        char pro; int t;
        cin>>a>>pro>>t>>pd;
        vec.push_back({a,pro,t,pd});
    }
    sort(vec.begin(),vec.end(),cmp);
    map<pair<string,char>,bool> ac; //gai ti shifou ac
    map<string,int> time; // zongshijian
    map<pair<string,char>,int>fas;
    map<string,int> ans; // fengbang qian timu
    for(int i=0;i<n;i++)
    {
        Node tmp=vec[i];
        if(tmp.pd=="Accepted")
        {
            if(ac[{tmp.name,tmp.p}]==false) // un ac
            {
                ac[{tmp.name,tmp.p}]=true;
                time[{tmp.name}]+=tmp.t+fas[{tmp.name,tmp.p}];
                ans[tmp.name]++;
            }
        }
        else if(tmp.pd=="Rejected")
        {
            fas[{tmp.name,tmp.p}]+=20;
        }
        else 
        {
            continue;
        }
    }
    map<string,int> fb; // fengbanghou guode timu
    map<string,int> fbt; //fengbang hou de fashi
    for(int i=0;i<n;i++)
    {
        Node tmp=vec[i];
        if(tmp.pd=="Unknown")
        {
            if(ac[{tmp.name,tmp.p}]==false) // un ac
            {
                ac[{tmp.name,tmp.p}]=true;
                fbt[{tmp.name}]+=tmp.t+fas[{tmp.name,tmp.p}];
                fb[tmp.name]++;
            }
        }
    }
    int cnt=-1;
    for(auto x:ans)
    {
        cnt=max(cnt,x.second);
    }
    set<string> team;
    int fanltime=INT_MAX;
    for(auto x:ans)
    {
        if(x.second==cnt)
        {
            fanltime=min(fanltime,time[{x.first}]);
        }
    }
    for(int i=0;i<n;i++)
    {
        Node tmp=vec[i];
        if(ans[tmp.name]+fb[tmp.name]<cnt)
        {
            continue;
        }
        else if(ans[tmp.name]+fb[tmp.name]>cnt)
        {
            team.insert(tmp.name);
        }
        else // same
        {
            if(time[tmp.name]+fbt[tmp.name]<=fanltime)
            {
                team.insert(tmp.name);
            }
        }
    }
    for(auto x:team) cout<<x<<" ";
    cout<<'\n';
}
signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
// 1
// 5
// T1 A 2 Rejected
// T1 A 20 Accepted
// T2 C 40 Accepted
// T3 D 291 Unknown
// T1 A 290 Unknown
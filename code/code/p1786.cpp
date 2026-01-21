#include<bits/stdc++.h>
using namespace std;
#define int long long
map<string,int> mp;
map<int,string> cp;



int rs_table[]={1,2,2,4,7,25,INT64_MAX};
struct Node{
    string na;
    string zw;
    int bg;
    int lev;
    int id;
};vector<Node> ans[10];
vector<Node> vec2;

bool cmp1(Node i, Node j)
{
    if(i.bg==j.bg)
    {
        return i.id<j.id;
    }
    else {
        return i.bg>j.bg;
    }
}

bool cmp2(Node i, Node j)
{
    if(i.lev==j.lev) return i.id<j.id;
    else return i.lev>j.lev;
}


signed main()
{
    mp["BangZhu"]=0;
    mp["FuBangZhu"]=1;
    mp["HuFa"]=2;
    mp["ZhangLao"]=3;
    mp["TangZhu"]=4;
    mp["JingYing"]=5;
    mp["BangZhong"]=6;

    cp[0]="BangZhu";
    cp[1]="FuBangZhu";
    cp[2]="HuFa";
    cp[3]="ZhangLao";
    cp[4]="TangZhu";
    cp[5]="JingYing";
    cp[6]="BangZhong";

    int n;
    cin>>n;
    Node self;
    for(int i=0;i<n;i++)
    {
        string s1,s2;
        int a,b;
        cin>>s1>>s2>>a>>b;
        if(s1=="absi2011") self={s1,s2,a,b,i};
        else if(mp[s2]==0||mp[s2]==1)
        {
            ans[mp[s2]].push_back({s1,s2,a,b,i});
            //cout<<s1<<"\n";
            rs_table[mp[s2]]--;
        }
        else vec2.push_back({s1,s2,a,b,i});
    }

    sort(vec2.begin(),vec2.end(),cmp1);

    ans[mp[self.zw]].push_back(self);
    rs_table[mp[self.zw]]--;

    int t=0;
    for(Node x:vec2)
    {
        while(rs_table[t]==0) t++;
        if(rs_table[t]!=0)
        {
            ans[t].push_back(x);
            rs_table[t]--;
        }
    }

    for(int i=0;i<7;i++)
    {
        sort(ans[i].begin(),ans[i].end(),cmp2);
        for(auto x:ans[i])
        {
            cout<<x.na<<" "<<cp[i]<< " "<<x.lev<<'\n';
            
        }
    }
}
// 9
// absi2011 BangZhu 100000 66
// RenZaiJiangHu FuBangZhu 80000 60
// absi201 FuBangZhu 90000 61
// BingQiLingDeYanLei HuFa 89000 58
// Lcey HuFa 30000 49
// BangYou3 ZhangLao 1000 1
// BangYou1 TangZhu 100 40
// BangYou2 JingYing 40000 10
// BangYou4 BangZhong 400 1
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    int cnt;
    bool operator<(const Node o)
    {
        if(o.cnt!=cnt) return cnt>o.cnt;
        else return id<o.id;
    }
};

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<bool> f(k+1,false);
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        f[x]=true;
    }
    map<pair<int,int>,int> c1,c3;
    map<int,int>c2; //c2_y代表只增加y，产生多少个新消息
    map<int,set<int>>C3;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(f[a]&&f[b])
        {
            c1[{a,b}]++;
            ans++;
        }
        else if(!f[a]&&f[b])
        {
            c2[a]++;
        }
        else if(f[a]&&!f[b])
        {
            c2[b]++;
        }
        else 
        {
            if(a==b) c2[a]++;
            else 
            {
                c3[{b,a}]++;
                c3[{a,b}]++;
                C3[a].insert(b);
                C3[b].insert(a);
            }
        }
    }
    vector<Node> C2;
    for(auto x:c2) C2.push_back({x.first,x.second});
    sort(C2.begin(),C2.end());

    int res=0;
    for(int i=1;i<=k;i++)
    {
        int add=0;
        if(!f[i]) //
        {
            add+=c2[i]; //加入i后新增的
            // if(C3[i].size()==0) //没有互不认识，无脑选max_c2
            // {
                int t2=0;
                if(C2.size())
                {
                    if(C2[0].id==i) 
                    {
                        if(C2.size()>1) t2=C2[1].cnt;
                    }
                    else t2=C2[0].cnt;
                }
            // }
            res=max(res,add+t2);
            if(C3[i].size()!=0)
            {
                //枚举所有与i有关的c3关系，找到c3+c2综合最大的
                int tmp=0;
                for(auto x:C3[i])
                {
                    tmp=max(tmp,(c3[{i,x}]+(x!=i)*c2[x]));
                }
                add+=tmp;
            }
        }
        res=max(res,add);
    }
    cout<<ans+res<<'\n';
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
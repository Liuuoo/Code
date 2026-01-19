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

int solve(int n,int m,int k,vector<int> fri,vector<pair<int,int>> vec)
{
    // int n,m,k;
    // cin>>n>>m>>k;
    vector<bool> f(k+1,false);
    for(int i=1;i<=n;i++) 
    {
        int x;
        x=fri[i-1];
        // cin>>x;
        f[x]=true;
    }
    map<pair<int,int>,int> c1,c3;
    map<int,int>c2; //c2_y代表只增加y，产生多少个新消息
    map<int,set<int>>C3;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        a=vec[i-1].first;
        b=vec[i-1].second;
        // cin>>a>>b;
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
    // cout<<ans+res<<'\n';
    return (ans+res);
}

int calc(map<int,vector<int>> &M, vector<bool>&f)
{
    int res=0;
    for(auto x:M)
    {
        if(!f[x.first]) continue;
        for(auto y:x.second)
        {
            if(f[y]) res++;
        }
    }
    return res;
}

int solve2(int n,int m,int k,vector<int> &fri,vector<pair<int,int>> &vec)
{
    vector<bool> f(k+1,false);
    for(int i=0;i<n;i++) f[fri[i]]=true;

    map<int,vector<int>> M;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        a=vec[i-1].first;
        b=vec[i-1].second;
        M[a].push_back(b);
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=i;j<=k;j++)
        {
            bool I=f[i];
            bool J=f[j];
            f[i]=true;
            f[j]=true;
            ans=max(ans,calc(M,f));
            f[i]=I;
            f[j]=J;
        }
    }
    return ans;
}

int main()
{
    srand(time(0));
    int T=1234;
    // cin>>T;
    while(T--)
    {
        int k=rand()%100+3; // all
        int m=rand()%502+3; // coms
        int n=rand()%k+1; //friends
        set<int> S;
        while(S.size()!=n)
        {
            S.insert(rand()%k+1);
        }
        vector<int>fri;
        vector<pair<int,int>> vec;
        for(auto x:S) fri.push_back(x);
        for(int i=1;i<=m;i++)
        {
            int a=rand()%k+1;
            int b=rand()%k+1;
            vec.push_back({a,b});
        }
        int ans1=solve(n,m,k,fri,vec);
        int ans2=solve2(n,m,k,fri,vec);
        if(ans1!=ans2)
        {
            cout<<ans1<<" "<<ans2<<"\n";
            cout<<n<<" "<<m<<" "<<k<<'\n';
            for(auto i:fri) cout<<i<<" ";
            cout<<'\n';
            for(auto i:vec) cout<<i.first<<" "<<i.second<<"\n";
            // cout<<"NO\n";
            return 0;
        }
        // else cout<<"yes\n";
    }   
}
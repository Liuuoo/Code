#include<bits/stdc++.h>
using namespace std;
int X,C,D,H,S;
int ans=0;
vector<int> ab(6); //剩余技能
vector<int> gg[20];//每一组的技能使用情况
// set<vector<int>> st;
set<pair<vector<vector<int>>,vector<int>>>st;
map<pair<int,vector<int>>,bool> V1;
bool jud(int x,vector<int>&g)
{
    int sum=0;
    for(int i=0;i<4;i++) sum+=g[i];
    if(sum<5) return false;

    if(gg[x][5]==0&&gg[x][4]==0)
    {
        // 以下是使用
        if(gg[x][0]==1)
        {
            if(g[1]>=2) return true;
        }
        if(gg[x][1]==1)
        {
            if(g[0]>=2) return true;
        }
        if(gg[x][2]==1)
        {
            if(g[2]>=2) return true;
        }
        if(gg[x][3]==1)
        {
            if(g[3]>=2) return true;
        }
        //以下是不使用
        for(int i=0;i<4;i++) 
        {
            if(g[i]==5) return true;
        }
    }
    else if(gg[x][5]==0) //一张万能
    {
        // 以下是使用
        if(gg[x][0]==1)
        {
            if(g[1]>=1) return true;
        }
        if(gg[x][1]==1)
        {
            if(g[0]>=1) return true;
        }
        if(gg[x][2]==1)
        {
            if(g[2]>=1) return true;
        }
        if(gg[x][3]==1)
        {
            if(g[3]>=1) return true;
        }
        //以下没有变色牌
        for(int i=0;i<4;i++) 
        {
            if(g[i]>=4) return true;
        }
    }
    else if(gg[x][4]==0) //一张复制
    {
                // 以下是使用
        if(gg[x][0]==1)
        {
            if(g[1]>=1) return true;
        }
        if(gg[x][1]==1)
        {
            if(g[0]>=1) return true;
        }
        if(gg[x][2]==1)
        {
            if(g[2]>=1) return true;
        }
        if(gg[x][3]==1)
        {
            if(g[3]>=1) return true;
        }
        //以下没有变色牌
        for(int i=0;i<4;i++) 
        {
            if(g[i]>=4) return true;
        }
    }
    else //一张变色+一张复制。显然一定有三张同样颜色
    {
        for(int i=0;i<4;i++) // +一张变色。复制同样变色牌
        {
            if(gg[x][i]>=1) return true;
        }
        //以下没有变色牌
        for(int i=0;i<4;i++) 
        {
            if(g[i]>=3) return true;
        }
    }
    return false;
}

int calc(int i,int j,int k,int l,int m,int n,int nx,vector<vector<int>>&g)
{
    int res=0;
    for(int I=0;I<nx;I++)
    {
        vector<int> vec(6,0);
        if(i==I&&ab[0]==1) vec[0]=1;
        if(j==I&&ab[1]==1) vec[1]=1;
        if(k==I&&ab[2]==1) vec[2]=1;
        if(l==I&&ab[3]==1) vec[3]=1;
        if(m==I&&ab[4]==1) vec[4]=1;
        if(n==I&&ab[5]==1) vec[5]=1;
        gg[I]=vec;
        if(jud(I,g[I])) res++;
    }
    return res;
}

void dfs(int x,vector<vector<int>>g,vector<int>ab) //gij--i组中j数有多少个 abi i技能剩余多少
{
    int ts=0;
    int nx=X+1;
    for(int i=0;i<g[X].size();i++) ts+=g[X][i];
    if(ts<5) nx--;
    for(int i=0;i<nx;i++) //第一个技能去了i组
    {
        for(int j=0;j<nx;j++)
        {
            for(int k=0;k<nx;k++)
            {
                for(int l=0;l<nx;l++)
                {
                    for(int m=0;m<nx;m++)
                    {
                        for(int n=0;n<nx;n++)
                        {
                            ans=max(calc(i,j,k,l,m,n,nx,g),ans);
                        }
                    }
                }
            }
        }
    }
}

void group(int x,int c,int d,int h,int s,vector<vector<int>>&g,vector<int> &ab)
{
    if(x==X-1)
    {
        g[x]={C-c,D-d,H-h,S-s};
        //发动技能
        if(st.find({g,ab})==st.end()) 
        {
            dfs(0,g,ab);
            st.insert({g,ab});
        }
        return;
    }
    for(int i=0;i<=min(5,C-c);i++) //c
    {
        for(int j=0;j<=min(5,D-d);j++) //d
        {
            for(int k=0;k<=min(5,H-h);k++) //h
            {
                if(S-s<5-(i+j+k))
                {
                    continue;
                }
                int l=(5-i-j-k);
                if(l>S-s) continue;
                int nc=c+i;
                int nd=d+j;
                int nh=k+h;
                int ns=l+s;
                // if(st.find(g[x])!=st.end()) continue;
                // st.insert(g[x]);
                g[x]={i,j,k,l};
                group(x+1,nc,nd,nh,ns,g,ab);
            }
        }
    }
}

void solve()
{
    ans=0;
    int n;
    cin>>n;
    vector<vector<int>> g(20);
    for(int i=0;i<20;i++)
    {
        g[i].resize(4);
        gg[i].clear();
    }
    C=0,D=0,H=0,S=0;
    for(int i=1;i<=n;i++)
    {
        char c1,c2;
        cin>>c1>>c2;
        if(c2=='C') C++;
        if(c2=='D') D++;
        if(c2=='H') H++;
        if(c2=='S') S++;
    }
    for(int i=0;i<6;i++) ab[i]=0;
    for(int i=0;i<6;i++)
    {
        int x;
        cin>>x;
        ab[i]=x;
    }   
    X=(n+4)/5;
    group(0,0,0,0,0,g,ab);
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
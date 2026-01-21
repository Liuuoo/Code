#include<bits/stdc++.h>
using namespace std;
#define int long long
int ds=0;
void dfs(vector<char>vec)
{
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i]=='?')
        {
            vec[i]='1';
            dfs(vec);
            vec[i]='0';
            dfs(vec);
        }
        if(i==vec.size()-1)
        {
            int cnt=0;
            int res=0;
            for(int j=1;j<vec.size();j++)
            {
                if(vec[j]=='1') cnt++;
                else res+=cnt;
            }
            ds=max(ds,res);
        }
    }

}

int calc(int pos,vector<char>vec)
{
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i]=='?')
        {
            if(i<pos)
            {
                vec[i]='1';
            }
            else vec[i]='0';
        }
    }
    int cnt=0;
    int res=0;
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i]=='1') cnt++;
        else res+=cnt;
    }
    return res;
}

int t_serch(int l,int r,vector<char>&vec,vector<int>&pos)
{
    while(r-l>2)
    {
        int lmid=l+(r-l)/3;
        int rmid=r-(r-l)/3;
        int lans=calc(pos[lmid],vec);
        int rans=calc(pos[rmid],vec);
        if(lans>=rans)
        {
            r=rmid;
        }
        else l=lmid;
    }
    int res=0;
    for(int i=l;i<=r;i++)
    {
        res=max(res,calc(pos[i],vec));
    }
    return res;
}

int solve1(vector<char> &vec,vector<int>&pos)
{
    if(pos.size()==0)
    {
        int cnt=0;
        int res=0;
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]=='1') cnt++;
            else res+=cnt;
        }
        return res;
    }
    else 
    {
        int res=0;
        for(int i=0;i<pos.size();i++) 
        {
            res=max(res,calc(pos[i],vec));
        }
        return res;
    }
}

int solve2(vector<char> &vec,vector<int>&pos)
{
    if(pos.size()==0)
    {
        int cnt=0;
        int res=0;
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]=='1') cnt++;
            else res+=cnt;
        }
        return res;
    }
    else 
    {
        int res=0;
        int cnt=0;
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]=='1'||vec[i]=='?') cnt++;
            else res+=cnt;
        }
        return max(res,t_serch(0,pos.size()-1,vec,pos));
    }

}

void solve()
{
    int n;
    ds=0;
    // cin>>n;
    n=rand()%12+1;
    vector<char> vec;
    vec.push_back('$');
    vector<int> pos;
    for(int i=1;i<=n;i++)
    {
        char c;
        // cin>>c;
        int r=rand()%3;
        if(r==0) c='0';
        else if(r==1) c='1';
        else c='?';
        // cout<<c;
        vec.push_back(c);
        if(c=='?') pos.push_back(i);
    }

    int ans1=solve1(vec,pos);
    int ans2=solve2(vec,pos);
    dfs(vec);
    if(ans2!=ds)
    {
        for(int i=1;i<=n;i++) cout<<vec[i];
        cout<<endl;
        cout<<ans2<<" "<<ds<<endl;
        exit(0);
    }
    else 
    {
        cout<<ans2<<" "<<ds<<endl;
    }
    cout<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(0));
    int T=123455;
    // cin>>T;
    while(T--)
    {
        solve();
    }
}
// 4
// 3
// 110
// 3
// 1?0
// 4
// ????
// 7
// 1?0?0?1
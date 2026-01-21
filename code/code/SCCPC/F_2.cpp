#include<bits/stdc++.h>
using namespace std;
#define int long long
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
    cin>>n;
    vector<char> vec;
    vec.push_back('$');
    vector<int> pos;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        vec.push_back(c);
        if(c=='?') pos.push_back(i);
    }
    int ans2=solve2(vec,pos);
    cout<<ans2<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}

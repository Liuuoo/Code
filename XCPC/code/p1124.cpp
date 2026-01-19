#include<bits/stdc++.h>
using namespace std;
int n,p;
string s;
bool vis[111101];

bool cmp(string s1,string s2)
{
    return s1[0]<s2[0];
}

int find(string s,char c)
{
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]==c&&!vis[i])
        {
            return i;
        }
    }
    return 0;
}

string solve()
{
    string tmp=s;
    sort(tmp.begin(),tmp.end());

    p--;
    for(int i=0;i<s.size();i++)
    {
        if(tmp[i]==s[p]) 
        {
            p=i;
            break;
        }
    }
    
    char nex=s[p];
    string ans;

    int cnt=n;

    while(cnt--)
    {
        ans+=nex; 
        vis[p]=true;
        p=find(tmp,s[p]);
        assert(p>=0&&p<n);
        nex=s[p];
    }
    return ans;
}

pair<string,int> data()
{
    string res[n+1];
    for(int i=0;i<n;i++)
    {
        string tmp1,tmp2;
        for(int j=0;j<i;j++)
        {
            tmp1+=s[j];
        }
        for(int j=i;j<n;j++)
        {
            tmp2+=s[j];
        }
        // cout<<tmp2+tmp1<<'\n';
        res[i]=tmp2+tmp1;
    }
    stable_sort(res,res+n,cmp);
    string ans;
    int ansp=-1;
    for(int i=0;i<n;i++)
    {
        // cout<<res[i]<<'\n';
        string tmp;
        tmp+=res[i][n-1];
        for(int j=0;j<n-1;j++)
        {
            tmp+=res[i][j];
        }
        if(tmp==s) ansp=i;
        ans+=res[i][n-1];
    }
    // cout<<ans<<" "<<ansp+1<<'\n';
    return{ans,ansp+1};
}

int main()
{
    // srand(time(0));
    // while(1)
    // {  
    //     n=rand()%101+1;
    //     s="";
    //     for(int i=0;i<n;i++)
    //     {
    //         s+=rand()%26+'a';
    //     }
    //     // cout<<s<<'\n';
    //     cout<<n<<" "<<s<<'\n';  
    //     auto dat=data();
    //     string ns=dat.first;
    //     int np=dat.second;

    //     if(solve(ns,np)!=s)
    //     {
    //         cout<<ns<<" "<<np<<" "<<solve(ns,np)<<'\n';
    //         break;
    //     }

        // solve(ns,np);

    // }

    cin>>n>>s>>p;
    string res=solve();
    for(int i=res.size()-1;i>=0;i--) cout<<res[i];
}
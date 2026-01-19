#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
bool vis[N];

string calc(int l,int r,string s)
{
    string tmp;
    for(int i=l;i<=r;i++) tmp+=s[i];
    return tmp;
}

signed main()
{
    srand(time(0));
    while(1)
    {
        int n=rand()%5+1;
        int p=rand()%5+1;
        int ans=0;
        int f=0;
        // int p=0;
        string s;
        for(int i=0;i<n;i++) s+=rand()%10+'0';
        s="$"+s;
        // cin>>p>>s;
        int tmp=0;
        vis[0]=true;
        for(int i=1;i<s.size();i++)
        {
            if(vis[i-1]==true) f++;
            tmp=(tmp*10+s[i]-'0')%p;
            if((s[i]-'0')%p==0) tmp=0;
            if(tmp==0)
            {   
                if(!vis[i-1]) f++;
                vis[i]=true;
                ans+=f;
            }
        }
        // cout<<ans;
        int ans2=0;
        for(int i=1;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                string t=calc(i,j,s);
                if(stoll(t)%p==0)
                {
                    cout<<stoll(t)<<" ";
                    ans2++;
                }
            }
        }
        if(ans!=ans2) 
        {
            cout<<p<<" "<<s<<'\n';
            cout<<ans<<" "<<ans2;
            break;
        }
    }
}
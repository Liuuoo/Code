#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=123;
string s[N];
int n;
int vis[N]={0};
int ans=0;

void dfs(string ss,int nn)
{
    // if(nn>n) return;
    // cout<<ss<<"\n";
    ans=max(ans,(int)ss.size());
    int i;

    for(i=0;i<n;i++)
    {
        if(vis[i]<2)
        {
            vis[i]++;
            int j=0;
            int ln=0;
            int jud=1;
            if(ss.size()==1)jud=0;
            for(int j=ss.size()-1;j>=jud;j--)
            {
                int k=0;
                int l=j;
                while(l<ss.size()&&ss[l]==s[i][k])
                {
                    l++;
                    k++;
                }
                if(l==ss.size()) 
                {
                    ln=k;
                    break;
                }
            }
            string tmp;
            // cout<<ln<<'\n';
            if(ln>0)
            {
                for(int l=ln;l<s[i].size();l++)
                    tmp+=s[i][l];
                dfs(ss+tmp,nn+1);
                // cout<<t<<"\n"<<ss<<'\n';
            }
            vis[i]--;
        }

    }

}

signed main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    string c; cin>>c;
    dfs(c,0);
    cout<<ans;
}
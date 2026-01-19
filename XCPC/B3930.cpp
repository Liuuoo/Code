#include<bits/stdc++.h>
using namespace std;

int to_10(string s)
{
    int ans=0;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    {
        ans+=((s[i]-'0')*pow(2,i));
    }
    return ans;
}

bool jud(int n,int k) {
    return (n&(1<<k))!=0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int>vec;
    while(n--)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    vector<int>S;
    vector<bool>vis;
    for(auto x:vec) 
    {
        S.push_back(x);
        vis.push_back(1);
    }
    string ans;  ans.resize(32);
    for(int i=0;i<32;i++)
    {
        int cnt=0;
        bool flag=false;
        for(int j=0;j<S.size();j++)
        {
            int x=S[j];
            if(jud(x,31-i)&&vis[j])
            {
                cnt++;
            }
            if(cnt>1)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            ans[i]='1';
            for(int j=0;j<S.size();j++)
            {
                int tmp=S[j];
                if(vis[j]&&!jud(tmp,31-i))
                {
                    vis[j]=false;
                }
            }
        }
        else ans[i]='0';
        // for(auto x:ans) cout<<x; cout<<'\n';
    }
    
    cout<<to_10(ans);
}
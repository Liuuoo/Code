#include<bits/stdc++.h>
using namespace std;
bool is_vaild(char c)
{
    return (isdigit(c)||isalpha(c)||c=='_');
}
map<string,string>M;
map<string,bool>vis;
map<string,string>dp;
string root;
// map<string,set<string>> vec;
void dfs(string s)
{
    if(M.find(s)==M.end()||vis[s]) 
    {
        if(s!=root) vis[s]=false;
        cout<<s;
        return;
    }
    vis[s]=true;
    string ns=M[s];
    int i=0;
    while(i<ns.size())
    {
        int j=i;
        string tmp;
        while(j<ns.size()&&is_vaild(ns[j]))
        {
            tmp+=ns[j];
            j++;
        }
        dfs(tmp);
        if(tmp!=root) vis[tmp]=false;
        string tmp2;
        if(j<ns.size()&&!is_vaild(ns[j]))
        {
            tmp2+=ns[j];
            j++;
        }
        dfs(tmp2);
        if(tmp2!=root) vis[tmp2]=false;
        i=j;
    }
}

int main()
{
    int n;
    cin>>n;
    cin.ignore();

    while(n--)
    {
        string s;
        getline(cin,s);

        while(s.size()&&s.back()=='\n'||s.back()=='\r') s.pop_back();
        if(s[0]=='#')
        {
            int i=0;
            while(s[i]!=' ') i++;
            i++;
            string tmp1,tmp2;
            while(s[i]!=' '&&i<s.size()) 
            {
                tmp1+=s[i];
                i++;
            }
            i++;
            while(i<s.size())
            {
                tmp2+=s[i];
                i++;
            }
            if(s[1]=='d') 
            {
                M[tmp1]=tmp2;
            }
            else 
            {
                M.erase(tmp1);
            }

            cout<<'\n';
        }
        else 
        {
            int i=0;
            while(i<s.size())
            {
                string tmp;
                int j=i;
                while(j<s.size()&&is_vaild(s[j]))
                {
                    tmp+=s[j];
                    j++;
                }
                vis.clear();
                if(M.find(tmp)!=M.end()) 
                {
                    root=tmp;
                    dfs(tmp);
                    // cout<<dp[tmp];
                }
                else cout<<tmp;
                tmp="";
                while(j<s.size()&&!is_vaild(s[j]))
                {
                    tmp+=s[j];
                    j++;
                }
                cout<<tmp;
                i=j;
            }
            cout<<"\n";
        }
    }
}
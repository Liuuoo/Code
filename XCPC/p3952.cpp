#include<bits/stdc++.h>
using namespace std;

int del(string &s)
{
    int i=0;
    for(i=0;i<s.size();i++) if(s[i]=='(') break;
    if(s[i+1]=='1') return 0;
    else 
    {
        string num;
        for(int j=i+3;s[j]!=')';j++)
        {
            num+=s[j];
        }
        return stoi(num);
    }
}

pair<int,string> calc(string &s)
{
    int i=0;
    while(s[i]!=' ')i++;
    while(s[i]==' ')i++;
    string c;
    while(s[i]!=' ') 
    {
        c+=s[i];
        i++;
    }
    while(s[i]==' ')i++;
    string st,ed;
    while(s[i]!=' ')
    {
        st+=s[i];
        i++;
    }
    while(s[i]==' ')i++;
    while(i<s.size())
    {
        ed+=s[i];
        i++;
    }
    if(ed=="n"&&st!="n") return {1,c};
    else 
    {
        if(ed=="n"&&ed==st) return {0,c};
        if(ed=="n"||st=="n") return {-1,c};
        else 
        {
            int e=stoi(ed);
            int s=stoi(st);
            if(e>=s) return {0,c};
            else return {-1,c};
        }
    }
}

void solve()
{
    int n;  string s;
    cin>>n>>s;
    cin.ignore();
    int f=del(s);
    // cout<<f<<' ';
    string tmp[n];
    for(int i=0;i<n;i++)
    {
        getline(cin,tmp[i]);
        while(tmp[i].back()=='\n'||tmp[i].back()=='\r') tmp[i].pop_back();
    }
    stack<pair<int,string> > S;
    stack<int> check;
    int ans=0;
    map<string,bool> vis;
    for(int i=0;i<n;i++)
    {
        if(tmp[i][0]=='F')
        {
            auto np=calc(tmp[i]);

            if(vis[np.second]) 
            {
                cout<<"ERR\n";
                return;
            } 

            if(np.first!=-1) vis[np.second]=true;

            auto tp=np;
            if(!S.empty())
            {
                if(check.top()==-1) tp.first=S.top().first;
                else tp.first+=S.top().first;
            }
            else tp.first=max(0,tp.first);

            ans=max(ans,tp.first);

            S.push(tp);
            if(!check.empty())
            {
                if(check.top()==-1||np.first==-1) check.push(-1);
                else check.push(0);
            }
            else 
            {
                if(np.first==-1) check.push(-1);
                else check.push(0);
            }
        }
        else 
        {
            if(S.empty()) 
            {
                cout<<"ERR\n";
                return;
            }
            auto tp=S.top();
            vis[tp.second]=false;
            S.pop();
            check.pop();
        }
    }
    if(!S.empty())
    {
        cout<<"ERR\n";
        return;
    }
    // cout<<ans<<" ";
    if(ans==f) cout<<"Yes\n";
    else cout<<"No\n";
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
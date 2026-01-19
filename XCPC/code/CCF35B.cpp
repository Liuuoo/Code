#include<bits/stdc++.h>
using namespace std;
map<char,char>M;
string s;

string calc()
{
    string res;
    res+=s[0];
    for(int i=1;i<s.size()-1;i++)
    {
        char x=s[i];
        if(M.find(x)!=M.end())
        {
            res+=M[x];
        }
        else res+=x;
    }
    res+=s.back();
    return res;
}
vector<char>vcc;
int main()
{
    getline(cin,s);
    while(!s.empty()&&(s.back()=='\n'||s.back()=='\r')) s.pop_back();
    string ss=s;
    int n;
    cin>>n;
    cin.ignore();

    for(int i=1;i<=n;i++)
    {
        string t;
        getline(cin,t);
        while(!t.empty()&&(t.back()=='\n'||t.back()=='\r')) t.pop_back();
        M[t[1]]=t[2];
        vcc.push_back(t[1]);
    }
//	cout<<1;
    int m;
    cin>>m;
    cin.ignore();
    vector<string>ans(51110);
    int all=0;
    for(int i=1;i<=50000;i++)
    {
        ans[i]=calc();
        s.clear();
        s=ans[i];
        if(s==ss) all=i;
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        if(x<50000)cout<<ans[x]<<"\n";
        else 
        {   
            cout<<ans[x%all]<<'\n';
        }
    }
    return 0;
}
// #abcdefg#
// 6
// #ab#
// #bc#
// #cd#
// #de#
// #ef#
// #fg#

// #Hello World#
// 6
// #HH#
// #e #
// # r#
// #re#
// #oa#
// #ao#
// 3
// 1 2 3

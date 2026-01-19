#include<bits/stdc++.h>
using namespace std;
#define int long long
int a=1,b=1,c=1,d=1,e=1,f=1;

vector<int> del(string s)
{
    string tmp;
    vector<int> res;
    s+=',';
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==',')
        {
            res.push_back(stoi(tmp));
            tmp="";
        }
    }
    return res;
}

pair<string,vector<int>> calc(string s)
{
    string I; 
    string tmp;
    int cnt=0;
    vector<int> res;
    for(int i=0;i<s.size();i++)
    {
        if(I.empty()&&s[i]==' ')
        {
            int j=i+1;
            while(s[j]!=' ')
            {
                I+=s[j];
                j++;
            }
            i=j;
        }
        if(s[i]=='(')
        {

            int j=i+1;
            while(s[j]!=')')
            {
                tmp+=s[j];
                j++;
            }
            i=j;
        }
    }
    res=del(tmp);
    return{I,res};
}

signed main()
{
    string sss;
    cin>>sss;
    assert(sss.back()=='0');
    cin.ignore();
    string s1,s2,s3;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    cin>>sss;
    // cout<<s1<<"\n"<<s2<<'\n'<<s3<<'\n';

    string I,J;
    auto p1=calc(s1);
    auto p2=calc(s2);
    a=p1.second[0];
    b=p1.second[1];
    if(p1.second.size()==3) c=p1.second[2];
    
}
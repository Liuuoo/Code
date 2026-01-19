#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    while(s.size()&&(s.back()=='\n'||s.back()=='\r')) s.pop_back();
    s+=' ';
    string tmp;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' '&&tmp.size()) 
        {
            for(int i=tmp.size()-1;i>=0;i--)
            {
                cout<<tmp[i];
            }
            cout<<'\n';
            tmp="";
        }
        else tmp+=s[i];
    }
}
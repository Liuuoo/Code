#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    while(s.size()&&(s.back()=='\n'||s.back()=='\r')) s.pop_back();
    s+=' ';
    string tmp;
    int maxn=INT_MIN;
    int minn=INT_MAX;
    string maxs,mins;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' '||s[i]==','||s[i]=='.') 
        {
            if(maxn<(int)tmp.size())
            {
                maxn=tmp.size();
                maxs=tmp;
            }
            if(minn>(int)tmp.size())
            {
                minn=tmp.size();
                mins=tmp;
            }
            tmp="";
        }
        else tmp+=s[i];
    }
    cout<<maxs<<"\n"<<mins;
}
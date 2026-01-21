#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    s+=' ';
    string tmp;
    bool fis=false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' '&&tmp.size())
        {
            if(!fis) 
            {
                fis=1;
                cout<<tmp.size();
            }
            else cout<<","<<tmp.size();
            tmp="";
        }
        else tmp+=s[i];
    }
}
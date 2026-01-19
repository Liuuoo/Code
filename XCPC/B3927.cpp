#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string,string>M;
    while(n--)
    {
        string s1,s2;
        cin>>s1>>s2;
        M[s1]=s2;
    }
    string s;
    cin>>s;
    s+=",";
    string tmp;
    for(int i=0;i<s.size();i++)
    {
        if(isalpha(s[i]))
        {
            tmp+=s[i];
        }
        else 
        {
            if(tmp!=""&&M[tmp]=="") cout<<"UNK";
            else cout<<M[tmp];

            if(i!=s.size()-1) cout<<s[i];
            tmp="";
        }
    }
}
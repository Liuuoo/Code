#include<bits/stdc++.h>
using namespace std;
int cnt;
int main()
{
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i])) cnt++;
    }
    cout<<cnt;
}
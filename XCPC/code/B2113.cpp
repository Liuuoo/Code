#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i]+s[(i+1)%s.size()];
        cout<<c;
    }
}
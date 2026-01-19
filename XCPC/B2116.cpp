#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(islower(s[i])) s[i]=toupper(s[i]);
        else s[i]=tolower(s[i]);
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    {
        int nc=isupper(s[i])?'A':'a';
        cout<<char((s[i]-nc+3)%26+nc);
    }
}


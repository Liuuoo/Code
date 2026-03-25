#include<bits/stdc++.h>
using namespace std;

bool jud(string s)
{
    bool di=false, upper=false;
    for(auto x: s)
    {
        if(isdigit(x)) di=true;
        if(isupper(x)) upper=true;
    }
    return (di==true&&upper==true&&s.size()>=8);
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(jud(s)) cout<<"Y\n";
        else cout<<"N\n";
    }
}
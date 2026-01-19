#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string s2;
    int n;
    cin>>n;
    cin>>s>>s2;
    sort(s.begin(),s.end());
    sort(s2.begin(),s2.end());
    if(s==s2) 
    {
        cout<<"Yes";
    }
    else cout<<"No";
}
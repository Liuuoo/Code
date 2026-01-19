#include<bits/stdc++.h>
using namespace std;
int main()
{
    // cout<<(char)('z'+1);
    int n,m;
    cin>>n>>m;
    string s1, s2;
    cin>>s1>>s2;
    sort(s2.begin(),s2.end());
    s2=s2+"{";
    int i=0,j=0;
    while(1)
    {
        if(i==s1.size()) break;
        if(s1[i]>s2[j])
        {
            cout<<s2[j];
            j++;
        }
        else 
        {
            cout<<s1[i];
            i++;
        }
    }
    for(int k=j;k<s2.size()-1;k++) cout<<s2[k];
}
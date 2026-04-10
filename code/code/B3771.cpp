#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=a;i<=b;i++)
    {
        string s=to_string(i);
        char c=1;
        bool jud=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<=c)
            {
                jud=true;
                break;
            }
            else c=s[i];
        }
        if(!jud) ans++;
    }
    cout<<ans;
}
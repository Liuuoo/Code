#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string tmp;
    for(auto x:s) tmp+=x;
    vector<int>ans;

    sort(tmp.begin(),tmp.end());

    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]!=tmp.back())
        {
            ans.push_back(1);
            reverse(tmp.begin(),tmp.end());
            tmp.pop_back();
        }
        else 
        {
            ans.push_back(0);
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }
}
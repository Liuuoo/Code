#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r;
    cin>>n>>r;
    vector<char>ans;
    while(n)
    {
        int tmp=n%r;
        n/=r;
        if(tmp<10) ans.push_back(tmp+'0');
        else 
        {
            ans.push_back(tmp-10+'A');
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans) cout<<x;
}
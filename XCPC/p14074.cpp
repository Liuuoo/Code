#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxLen=0;

pair<string,int> to_bit(int x)
{
    string res;
    int cnt=0;
    while(x)
    {
        res+=(x%2+'0');
        if(x%2) cnt++;
        x/=2;
    }
    while(maxLen&&res.size()!=maxLen) res.push_back('0');
    reverse(res.begin(),res.end());
    return {res,cnt};
}

signed main()
{
    int l,r;
    cin>>l>>r;
    auto mp=to_bit(r);
    maxLen=mp.first.size();

    map<int,set<string>> M;
    for(int i=l;i<=r;i++)
    {
        pair<string,int> p;
        p=to_bit(i);
        if(p.second%2) M[p.second].insert(p.first);
    }
    for(int i=1;i<=10;i+=2)
    {
        for(auto x:M[i])
        {
            cout<<x<<'\n';
        }
    }
}
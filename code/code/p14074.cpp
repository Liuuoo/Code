#include<bits/stdc++.h>
using namespace std;
#define int long long
int max_len;


bool jud(int x)
{
    int cnt=0;
    while(x)
    {
        if(x%2!=0) cnt++;
        x/=2;
    }
    return(cnt%2);
}

string cha(int x)
{
    string res;
    while(x)
    {
        res+=(x%2)+'0';
        x/=2;
    }
    while(res.size()<max_len) res.push_back('0');
    reverse(res.begin(),res.end());
    return res;
}

signed main()
{
    int l,r;
    cin>>l>>r;
    max_len=cha(r).size();
    for(int i=l;i<=r;i++)
    {
        if(jud(i))
        {
            cout<<i<<" "<<cha(i)<<'\n';
        }
    }
}
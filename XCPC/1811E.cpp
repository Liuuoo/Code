#include<bits/stdc++.h>
using namespace std;

bool jud(int x)
{
    while(x)
    {
        if(x%10==4) return false;
        x/=10;
    }
    return true;
}

void solve1()
{   
    int n=10000;
    int cnt=0;
    vector<int> vec;
    while(vec.size()!=n)
    {
        if(jud(cnt)) vec.push_back(cnt);
        cnt++;
    }
    cout<<vec[400];
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve1();
    }
}
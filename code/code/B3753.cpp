#include<bits/stdc++.h>
using namespace std;
int ans=0;
bool fis=false;

void calc(int x)
{
    if(fis==false) cout<<1<<'\n',ans++,fis=true;
    else cout<<"dup\n", ans++;
    for(int i=0;i<x;i++)
    {
        cout<<"dup"<<'\n';
        cout<<"add"<<'\n';
        ans+=2;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    while(n)
    {
        vec.push_back(n%2);
        n/=2;    
    }
    // reverse(vec.begin(),vec.end());
    int las=0;
    int cnt=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]!=0)
        {
            calc(i-las);
            las=i;
            cnt++;
            ans++;
        }
    }
    for(int i=0;i<cnt-1;i++) cout<<"add\n";
    // cout<<ans;
}
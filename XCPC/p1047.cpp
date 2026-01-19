#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int l,m;
    cin>>l>>m;
    bool tree[l+1];
    for(int i=0;i<=l;i++) tree[i]=1;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        for(int i=u;i<=v;i++) tree[i]=false;
    }
    int cnt=0;
    for(int i=0;i<=l;i++)
    {
        if(tree[i]) cnt++;
    }
    cout<<cnt;
}
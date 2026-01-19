#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    set<int>S;
    while(m--)
    {
        int x;
        cin>>x;
        S.insert(x);
    }
    bool jud=false;
    for(int i=0;i<n;i++)
    {
        if(S.find(i)==S.end()) 
        {
            cout<<i<<" ";
            jud=true;
        }
    }
    if(jud) cout<<n;
}
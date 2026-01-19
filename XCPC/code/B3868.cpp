#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    bool jud1=1,jud2=1,jud3=1,jud4=1;
    for(auto x:s)
    {
        if(isalpha(x)) jud1=jud2=jud3=0;
        if(x>='2') jud1=0;
        if(x>='8') jud2=0;
        if(x>'9') jud3=0;
        if(x>'F') jud4=0;
    }
    cout<<jud1<<" "<<jud2<<" "<<jud3<<" "<<jud4<<'\n';
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
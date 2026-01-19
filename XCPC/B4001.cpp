#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int b=cbrt(n);
    bool jud=false;
    for(int i=1;i*i*i<=n;i++)
    {
        if(i*i*i==n)
        {
            jud=true;
        }
    }
    if(jud) cout<<"Yes";
    else cout<<"No";
}
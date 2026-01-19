#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans=1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ans*=x;
    }
    if(ans>1000000) cout<<">1000000";
    else cout<<ans;
}
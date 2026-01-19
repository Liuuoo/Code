#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    multiset<int,greater<int>>S;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>0) S.insert(x);
    }
    int cnt=0;
    while(S.size()>1)
    {
        cnt++;
        int mx=*S.begin();
        int mi=*S.rbegin();
        S.erase(S.begin());
        mx-=mi;
        if(mx>0) S.insert(mx);
    }
    cout<<cnt+(S.size()==1);
}
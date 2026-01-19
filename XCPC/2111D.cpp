#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m;
    cin>>n>>m;
    int a[m+1];
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a,a+m);

    deque<int> dq;
    for(int i=0;i<m;i++) dq.push_back(a[i]);
    // cout<<dq.front()<< " " <<dq.back();
            //cout<<dq.size()<<"\n";
    vector<int> cls(6);
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            for(int j=0;j<6;j++)
            {
                if(j%2==0) 
                    cls[j]=dq.front();
    
                else cls[j]=dq.back();
            }

            for(int j=0;j<6;j++) cout<<cls[j]<<" ";
            cout<<'\n';

            dq.pop_back();
            if(!dq.empty()) dq.pop_front();
        }
        else 
        {
            reverse(cls.begin(),cls.end());
            for(int j=0;j<6;j++) cout<<cls[j]<<" ";
            cout<<'\n';
        }

    }
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
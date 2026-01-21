#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        assert(n!=-1);
        int maxn=1;
        int node=1;
        map<int,vector<int>>M;
        for(int i=1;i<=n;i++)
        {
            cout<<"? "<<i<<" "<<n<<" ";
            for(int j=1;j<=n;j++)
            {
                cout<<j<<" ";
            }
            cout<<endl;
            cout.flush();
            int x;
            cin>>x;
            assert(x!=-1);
            M[x].push_back(i);
            if(x>maxn)
            {
                maxn=x;
                node=i;
            }
        }
        vector<int>ans;
        int t=n;
        while(M[t].size()==0) 
        {
            t--;
        }
        ans.push_back(M[t].back());
        for(int i=t-1;i>=1;i--)
        {
            if(M[i].size()==1) ans.push_back(M[i].back());
            else 
            {
                for(auto x:M[i])
                {
                    cout<<"? "<<ans.back()<<" "<<2<<" "<<x<<" "<<ans.back()<<endl;
                    cout.flush();
                    int q;
                    cin>>q;
                    assert(q!=-1);
                    if(q==2) 
                    {
                        ans.push_back(x); 
                        break;
                    }
                }
            }
        }
        cout<<"! "<<ans.size()<<" ";
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
        cout.flush();
    }
}
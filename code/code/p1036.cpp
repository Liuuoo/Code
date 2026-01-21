#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=12;
int a[N];
int ans[N];

int nn,k;
bool vis[N]={false};
int ans_num=0;
set<vector<int>> s;
int sum=0;

bool is_prime(int n)
{
    if(n==0||n==1) return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

void dfs(int n)
{
    // cout<<n<<" "<<k;
    if(n==k) 
    {
        int tmp=0;
        for(int i=0;i<k;i++) 
        {
            // cout<<ans[i]<<" ";
            tmp+=a[ans[i]];
        }
        vector<int> tmp_ans;
        if(is_prime(tmp)) 
        {
            for(int i=0;i<k;i++) 
            {
                tmp_ans.push_back(ans[i]);
                // cout<<ans[i]<<" ";
            }
            // cout<<'\n';
            sort(tmp_ans.begin(),tmp_ans.end());
            s.insert(tmp_ans);
        }
        return;
    }

    for(int i=0;i<nn;i++)
    {
        if(vis[i]==false)
        {
            // cout<<i<<" ";
            ans[n]=i;
            vis[i]=true;
            dfs(n+1);
            vis[i]=false;
        }
    }
    // cout<<ans_num.size();
}

signed main()
{

    cin>>nn>>k;
    for(int i=0;i<nn;i++)
    {
        cin>>a[i];
    }
    dfs(0);
    cout<<s.size();
    // for(auto x:s)
    // {
    //     for(auto y:x)
    //     {
    //         cout<<y<<" ";
    //     }
    //     cout<<"\n";
    // }
}
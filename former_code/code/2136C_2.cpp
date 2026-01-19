#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

void solve() {
    int n;
    cin>>n;
    
    int dp[n+1],cnt[n+1];
    for(int i=0;i<=n;i++) dp[i]=-1,cnt[i]=0;
    
    vector<int>vec;
    vec.push_back(0);
    
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        if(x<=n) vec.push_back(x);
    }
    
    int sz=vec.size();
    
    map<pair<int,int>,int>M;
    vector<int>occ(sz);
    
    for(int i=1;i<sz;i++) {
        cnt[vec[i]]++;
        occ[i]=cnt[vec[i]];
        M[{vec[i],cnt[vec[i]]}]=i;
    }
    
    function<int(int)> dfs = [&](int pos) -> int {
        if(pos>=sz) return 0;
        if(dp[pos]!=-1) return dp[pos];
        
        int res=dfs(pos+1);
        
        int val=vec[pos];
        int tar=occ[pos]+val-1;
        
        auto it=M.find({val,tar});
        if(it!=M.end()) {
            res=max(res,val+dfs(it->second+1));
        }
        
        return dp[pos]=res;
    };
    cout<<dfs(1)<<'\n';
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
}
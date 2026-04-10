#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> vec(n+1);
    for(int i=0;i<n;i++) cin>>vec[i];
    int ans=INT_MAX;
    int i=0,j=0;
    map<char,int> M;
    while(j<n)
    {
        for(auto c:vec[j]) M[c]++;
        while(i<n&&M.size()==26)
        {
            int tmp=0;
            for(auto x:M) tmp+=x.second;
            ans=min(ans,tmp);
            for(auto c:vec[i])
            {
                M[c]--;
                if(M[c]==0) M.erase(c);
            }
            i++;
        }
        j++;
    }
    cout<<ans;
}
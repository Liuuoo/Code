#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int dp[N][130];
int main()
{
    int p;
    cin>>p;
    string s;  cin>>s;
    int n=s.size(); 
    vector<int> vec(n+1); 
    for(int i=1;i<=n;i++) vec[i]=s[i-1]-'0';
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][vec[i]%p]=1; // 该位置切割得到的余数
        for(int j=0;j<p;j++) // 不切割得到的余数，则枚举上一个位置所有的余数
        {
            int J=(j*10+vec[i])%p; 
            dp[i][J]+=dp[i-1][j];
        } 
        cnt+=dp[i][0];
    }
    cout<<cnt;
}
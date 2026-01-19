#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 麦子(可能需要开long long类型)
    int las=1;  //原本剩余1
    int ans=1; 
    int n;  cin>>n;
    for(int i=2;i<=n;i++)
    {
        las*=2; // 当前格子=前一次格子*2 这边不仅*2，还更新了las
        ans+=las;
    }
    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int ans[N];//该位置（包括）前出现和为3倍数的次数
int las[3]; //记录上一个数出现的位置
int main()
{
    string s;
    cin>>s;
    s="$"+s;
    int p=0;
    las[0]=0;
    las[1]=-1;
    las[2]=-1;
    for(int i=1;i<s.size();i++)
    {
        int c=s[i]-'0';
        p=(p+c)%3;
        ans[i]=ans[i-1];
        if(las[p]!=-1)
        {
            ans[i]=max(ans[i-1],ans[las[p]]+1);
        }
        las[p]=i;
    }
    cout<<ans[s.size()-1];
}
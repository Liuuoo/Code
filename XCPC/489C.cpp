#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    if(n==1&&s==0)
    {
        cout<<"0 0";
        return 0;
    }
    if(s==0||s>9*n) 
    {
        cout<<"-1 -1";
        return 0;
    }
    else 
    {
        vector<int>ans;
        int tmp=0;
        for(int i=1;i<=n;i++)
        {
            int j;
            if(i==1) j=1;
            else j=0;
            for(;j<=9;j++)
            {
                if(s-tmp-j<=(n-i)*9)
                {
                    ans.push_back(j);
                    tmp+=j;
                    break;
                }
            }
        }
        for(auto x:ans) cout<<x;
        cout<<" ";
        ans.clear();
        tmp=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=9;j>=0;j--)
            {
                if(s-tmp-j>=0)
                {
                    ans.push_back(j);
                    tmp+=j;
                    break;
                }
            }
        }
        for(auto x:ans) cout<<x;
    }
}
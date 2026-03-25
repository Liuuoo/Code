#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> to_bit(int x)
{
    vector<int> res;
    while(x)
    {
        res.push_back(x%2);
        x/=2;
    }
    // reverse(res.begin(),res.end());
    return res;
}

int calc(int x)
{
    int res=0;
    if(x==0) return 0;
    vector<int> vec=to_bit(x);
    int pre_cnt=0;
    int pre_sum=0;
    for(int i=vec.size()-1;i>=0;i--)
    {
        if(vec[i]==0) continue;
        if(i==0)
        {   
            if(pre_cnt%2==1)
            {
                res+=pre_sum;
            }
        }
        else if(i==1)
        {
            if(pre_cnt%2==0)
            {
                res+=pre_sum+1;
            }
            else 
            {
                res+=pre_sum;
            }
        }
        else 
        {
            int cnt=(1<<i)/2;
            int r=(1<<i)-1;
            res+=pre_sum*cnt+(r*(r+1))/4; 
        }
        pre_sum=(pre_sum|(1<<i));
        pre_cnt++;
    }
    if(pre_cnt%2!=0) res+=x;
    return res;
}

signed main()
{
    int l,r;
    cin>>l>>r;
    cout<<calc(r)-calc(l-1);
}
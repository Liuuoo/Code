#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=23333333333333;
vector<int> vec;

bool is_primer(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

signed main()
{
    for(int i=2;i<=N;i++)
    {
        if(is_primer(i))
            vec.push_back(i*i);
    }

    cout<<vec.size();
    int ans=0;
    for(int i=0;i<vec.size();i++)
    {
        for(int j=i+1;j<vec.size();j++)
        {
            if(vec[i]*vec[j]<2333) continue;
            else if(vec[i]*vec[j]>=2333&&vec[i]*vec[j]<=N)
            {
                ans++;
                //cout<<i<<' '<<j<<'\n';
            }
            else break;
        }
    }
    cout<<ans<<'\n';
    cout<<"337413947303";
}
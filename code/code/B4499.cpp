#include<bits/stdc++.h>
using namespace std;

bool iscyc(int x)
{
    vector<int> vec;
    while(x)
    {
        vec.push_back(x%2);
        x/=2;
    }
    vector<int> v1=vec;
    reverse(v1.begin(),v1.end());
    return (vec==v1);
}

int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(iscyc(i))
        {
            ans++;
        }
    }
    cout<<ans;
}
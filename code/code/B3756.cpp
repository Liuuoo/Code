#include<bits/stdc++.h>
using namespace std;
vector<int> vec={5,7,9};

bool jud(int x)
{
    for(auto i:vec)
    {
        int tmp=x;
        while(tmp)
        {
            if(tmp%i==0)
            {
                return false;
            }
            tmp/=i;
        }
    }
    return true;
}

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=a;i<=b;i++)
    {
        if(jud(i))
        {
            ans++;
        }
    }
    cout<<ans;
}
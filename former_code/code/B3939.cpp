#include<bits/stdc++.h>
using namespace std;
bool is_primer(int n)
{
    if(n==1) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        if(is_primer(i))
        {
            string s=to_string(i);
            reverse(s.begin(),s.end());
            int nex=stoi(s);
            if(is_primer(nex))
            {
                cout<<i<<'\n';
            }
        }
    }
}
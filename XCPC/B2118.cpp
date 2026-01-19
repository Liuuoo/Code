#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    if(a.size()<=b.size())
    {
        for(int i=0;i<b.size();i++)
        {
            if(b[i]==a[0])
            {
                int cnt=0;
                string tmp;
                for(int j=i;cnt<a.size();j++)
                {
                    if(j==b.size()) break;
                    tmp+=b[j];
                    cnt++;
                }
                if(tmp==a) 
                {
                    cout<<a<<" is substring of "<<b;
                    return 0;
                }
            }
        }
    }
    else 
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[0])
            {
                int cnt=0;
                string tmp;
                for(int j=i;cnt<b.size();j++)
                {
                    if(j==a.size()) break;
                    tmp+=a[j];
                    cnt++;
                }
                if(tmp==b) 
                {
                    cout<<b<<" is substring of "<<a;
                    return 0;
                }
            }
        }
    }
    cout<<"No substring";
}
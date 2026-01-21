#include<bits/stdc++.h>
using namespace std;
map<int,int>M;
set<int>S;
int n;

void calc(int x)
{
    for(int i=2;i<=x;i++)
    {
        while(x%i==0)
        {
            M[i]++;
            x/=i;
        }
    }
}

int main()
{
    cin>>n;
    calc(n);
    int maxn=0;
    int ans=1;
    for(auto x:M)
    {
        S.insert(x.second);
        ans*=x.first;
    }
    if(S.size()==0)
    {
        cout<<1<<" "<<0;
    }
    else if(S.size()==1)
    {
        int i=0;
        while(1){
            if(pow(2,i)>=*S.rbegin()) 
            {
                if(pow(2,i)>*S.rbegin()) i++;
                break;
            }
            i++;
        }
        cout<<ans<<" "<<i;
    }
    else 
    {
        int i=0;
        while(1){
            if(pow(2,i)>=*S.rbegin()) 
            {
                break;
            }
            i++;
        }
        cout<<ans<<" "<<i+1;
    }
}
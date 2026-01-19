#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    char a[n];
    int cnt=0;
    int vis[1234]={0};
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        a[i]=c;
        if(!vis[c]) 
        {
            cnt++;
            vis[c]=true;
        }
    }
    for(int i=0;i<131;i++) vis[i]=0;
    int i=0,j=0,tmp=0;
    int len=INT_MAX;
    while(j<n)
    {
        while(tmp<cnt&&j<n)
        {
            if(!vis[a[j]]) tmp++;
            vis[a[j]]++;
            j++;
        }
        while(tmp>=cnt)
        {
            if(tmp==cnt)
            {
                len=min(j-i,len);
            }
            vis[a[i]]--;
            if(vis[a[i]]==0) tmp--;
            i++;
        }

    }
    cout<<len;
} 





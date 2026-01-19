#include<bits/stdc++.h>
using namespace std;
const int N=123;
string s[N];

bool jud(int x,int y,int z, int a)
{
    // cout<<x<<" "<<y<<" "<<z<<" "<<a<<'\n';
    int o=0;
    int l=0;
    for(int i=x;i<=z;i++)
    {
        for(int j=y;j<=a;j++)
        {
            // if(x==0;y==1&&z==3&&a==4)
            // cout<<i<<" "<<j<<'\n';
            if(s[i][j]=='0')o++;
            else l++;
        }
    }
    return o==l;
}

int main() {
    int n, m;
    cin>>n>>m;

    for(int i=0;i<n;i++) 
    {
        cin>>s[i];
    }
    int ans=0;
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<m;j++) 
        {
            for(int k=i;k<n;k++) 
            {
                for(int l=j;l<m;l++)
                {
                    if((i==k&&j==l))
                    continue;
                    
                    if(jud(i,j,k,l)) 
                    {
                       ans=max(ans,(k-i+1)*(l-j+1));
                    }
                    
                }
            }
        }
    }
    cout<<ans;
}
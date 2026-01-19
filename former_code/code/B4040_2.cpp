#include<bits/stdc++.h>
using namespace std;
int box[123][123];
int n,m;

bool jud(int x,int y)
{
    for(int i=x;i<=x+3;i++)
    {
        for(int j=y;j<=y+3;j++)
        {
            if(i<=0||i>n||j<0||j>m) return false;
            if(i==x||i==x+3||j==y||j==y+3) 
            {
                if(box[i][j]!=0) return false;
            }
            else if(box[i][j]==0) return false;
        }
    }
    return true;
}

void solve()
{

    cin>>n>>m;
    string s[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            box[i][j]=s[i-1][j-1]-'0';
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(jud(i,j)) {
                cout<<"Yes\n";
                return;
            }
        }
    }
    cout<<"No\n";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
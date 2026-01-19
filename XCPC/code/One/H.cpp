#include<bits/stdc++.h>
using namespace std;
const int N=((1<<22))+10;
int a[N];
bool vis[N];

int main()
{
    int n;
    cin>>n;
    queue<int>q;
    q.push(0);
    a[0]=0;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int i=0;i<=n;i++)
        {
            int v=f^(1<<i);
            if(!vis[v])
            {
                vis[v]=true;
                a[v]=1-a[f];
                q.push(v);
            } 
        }
    }
    for(int i=0;i<(1<<n);i++)
    {
        cout<<a[i];
    }
}
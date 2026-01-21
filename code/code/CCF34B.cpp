#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>bod;
vector<int>vec(50000);

void fill(int a,int b)
{
    int t=0;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            bod[i][j]=vec[t++];
        }
    }
}
void dfsz(int a,int b)
{
    bod.resize(a);
    for(int i=0;i<a;i++) bod[i].resize(b);
    fill(a,b);
}
void change(int a,int b)
{
    int t=0;
    for(int i=0;i<b;i++)
    {
        for(int j=0;j<a;j++)
        {
            vec[t++]=bod[j][i];
        }
    }
}

int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=0;i<n*m;i++) 
    {
        int x;
        cin>>x;
        vec[i]=x;
    }
    dfsz(n,m);
    int nn,mm;
    nn=n,mm=m;
    while(t--)
    {
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1)
        {
            dfsz(a,b);
            nn=a,mm=b;
        }
        else if(op==2)
        {
            change(nn,mm);
            dfsz(mm,nn);
            swap(nn,mm);
        }
        else 
        {
            cout<<bod[a][b]<<'\n';
        }
    }
}
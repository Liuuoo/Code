#include<bits/stdc++.h>
using namespace std;
const int N=5001;

int main()
{
    long long x0,a,b,c,d;
    cin>>x0>>a>>b>>c>>d;
    int n,m,q;
    cin>>n>>m>>q;
    int T[(n+1)*(m+1)];
    int X[(n+1)*(m+1)];
    X[0]=x0;
    for(int i=1;i<=n*m;i++)
    {
        X[i]=((a*X[i-1]*X[i-1])%d+(b*X[i-1])%d+c)%d;
        T[i]=i;
    }
    for(int i=1;i<=n*m;i++)
    {
        int f=i;
        int s=(X[i]%i)+1;
        swap(T[f],T[s]);
    }
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        swap(T[u],T[v]);
    }
    for(int i=1;i<=n*m;i++) X[T[i]]=i;

    int L[n+1],R[n+1];
    for(int i=1;i<=n;i++)
    {
        L[i]=1;
        R[i]=m;
    }

    int cnt=0;
    for(int i=1;i<=m*n;i++)
    {
        int p=X[i];
        int row=(p+m-1)/m;
        int col=(p-1)%m+1;
        if(col>=L[row]&&col<=R[row])
        {
            cout<<i<<" ";
            cnt++;
            if(cnt==n+m-1) return 0;
            for(int j=1;j<row;j++)
            {
                R[j]=min(R[j],col);
            }
            for(int j=row+1;j<=n;j++)
            {
                L[j]=max(L[j],col);
            }
        }
    }
}
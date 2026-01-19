#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
vector<int> fa;
bool vis[N];
struct UF
{
    UF(int n)
    {
        fa.resize(n+10);
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    int find(int x)
    {
        if(x==fa[x]) return x;
        else 
            return fa[x]=find(x);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y) return;
        else 
        {
            fa[x]=y;
            return;
        }
    }
};

signed main()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    // UF uf(n);
    // int a[n+1]={0};
    // int b[n+1]={0};
    vector<int> A[n+1];
    vector<int> B[n+1];
    int ini;
    set<int>S1;
    for(int i=1;i<=m;i++)
    {
        int L=(i*p+q)%n+1;
        int R=(i*q+p)%n+1;
        A[L].push_back(i);
        B[R].push_back(i);
        S1.insert(L);
        S1.insert(R);
        ini=L;
        // uf.merge(L,R);
    }
    // p=ini;
    int ans[n+1];
    // int np=p;
    // set<int,greater<int>> S;
    // S.insert(0);
    // S.insert(m);
    // while(1)
    // {
    //     int x=*S.begin();
    //     ans[np]=x;
    //     while(!A[np].empty())
    //     {
    //         S.insert(A[np].back());
    //         A[np].pop_back();
    //     }
    //     // if(b[np]==x)
    //     // {
    //     //     while(S.size()>1)
    //     //     {
    //     //         S.erase(S.begin());
    //     //         int tmp=*S.begin();
    //     //         int R=fa[tmp];
    //     //         if(np<p)
    //     //         {
    //     //             if(R>=np&&R<=p) 
    //     //             {
    //     //                 break;
    //     //             }
    //     //         }
    //     //         else 
    //     //         {
    //     //             if(R<=p||R>=np)
    //     //             {
    //     //                 break;
    //     //             }
    //     //         }
    //     //     }
    //     // }
    //     np++;
    //     np%=n;
    //     if(np==p) break;
    // }
    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
}
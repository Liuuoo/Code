#include<bits/stdc++.h>
using namespace std;
const int N=2200;
int pri[N];
struct Node 
{
    int c;
    int v;
};

int main()
{
    int n,l;
    cin>>n>>l;
    for(int j=0;j<2200;j++) pri[j]=INT_MAX;
    vector<Node> vec(n+1);
    for(int i=1;i<=n;i++)
    {
        int c,v;
        cin>>c>>v;
        vec[i]={c,v};
    }
    pri[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=l;j>=0;j--)
        {
            int need=max(0,j-vec[i].v);
            if(pri[need]!=INT_MAX)
            {
                pri[j]=min(pri[j],pri[need]+vec[i].c);  
            }
        }
    }
    // for(int i=0;i<=l+1;i++) if(pri[n][i]!=INT_MAX) cout<<i<<" "<<pri[n][i]<<" ";
    if(pri[l]!=INT_MAX) cout<<pri[l];
    else cout<<"no solution";
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N];
struct segmentTree
{
    vector<int> tree,tag;
    segmentTree(int n) 
    {
        tree.resize(n<<2);
        tag.resize(n<<2);
    }
    int ls(int x) {
        return x<<1;
    }
    int rs(int x)
    {
        return x<<1|1;
    }

    void push_up(int p)
    {
        tree[p]=tree[ls(p)]+tree[rs(p)];
    }

    void build(int p,int pl,int pr)
    {
        tag[p]=0;
        if(pl==pr) 
        {
            tree[p]=a[pl];
            return;
        }
        int mid=(pl+pr)>>1;
        build(ls(p),pl,mid);
        build(rs(p),mid+1,pr);
        push_up(p);
    }

    void addtag(int p,int pl,int pr,int d)
    {
        tag[p]+=d;
        tree[p]+=(pr-pl+1)*d;
    }
    
    void push_down(int p,int pl,int pr)
    {
        if(tag[p])
        {
            int mid=(pl+pr)>>1;
            addtag(ls(p),pl,mid,tag[p]);
            addtag(rs(p),mid+1,pr,tag[p]);
            tag[p]=0;
        }
    }

    void update(int L,int R,int p,int pl,int pr,int d)
    {
        if(L<=pl&&R>=pr)
        {
            addtag(p,pl,pr,d);
            return ;
        }
        push_down(p,pl,pr);
        int mid=(pl+pr)>>1;
        if(L<=mid)
        {
            update(L,R,ls(p),pl,mid,d);
        }
        if(R>mid)
        {
            update(L,R,rs(p),mid+1,pr,d);
        }
        push_up(p);
    }
    
    int query(int L,int R,int p,int pl,int pr)
    {
        if(L<=pl&&R>=pr)
        {
            return tree[p];
        }
        push_down(p,pl,pr);
        int res=0;
        int mid=(pl+pr)>>1;
        if(L<=mid) res+=query(L,R,ls(p),pl,mid);
        if(R>mid) res+=query(L,R,rs(p),mid+1,pr);
        return res;
    }

};

signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    segmentTree T(n);
    T.build(1,1,n);
    while(m--)
    {
        int j;
        cin>>j;
        if(j==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            T.update(x,y,1,1,n,k);
        }
        else 
        {
            int x,y;
            cin>>x>>y;
            cout<<T.query(x,y,1,1,n)<<'\n';
        }
    }
}
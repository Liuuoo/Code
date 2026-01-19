#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N];
int n,m;
struct segmentTree
{
    vector<int> tree,tag,tag2;
    segmentTree(int n) 
    {
        tree.resize(n<<2);
        tag.resize(n<<2);
        tag2.resize(n<<2);
    }

    int ls(int x) 
    {
        return x<<1;
    }

    int rs(int x)
    {
        return x<<1|1;
    }

    void push_up(int p)
    {
        tree[p]=tree[ls(p)]+tree[rs(p)];
        tree[p]%=m;
    }

    void build(int p,int pl,int pr)
    {
        tag[p]=0;
        tag2[p]=0;
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
        tree[p]%=m;
    }

    void multitag(int p,int pl,int pr,int d)
    {
        tag2[p]=d;
        tree[p]*=d;
        tree[p]%=m;
    }

    void push_down_add(int p,int pl,int pr)
    {
        if(tag[p])
        {
            int mid=(pl+pr)>>1;
            addtag(ls(p),pl,mid,tag[p]);
            addtag(rs(p),mid+1,pr,tag[p]);
            tag[p]=0;
        }
    }

    void push_down_mulity(int p,int pl,int pr)
    {
        if(tag2[p])
        {
            int mid=(pl+pr)>>1;
            multitag(ls(p),pl,mid,tag2[p]);
            multitag(rs(p),mid+1,pr,tag2[p]);
            tag2[p]=0;
        }
    }

    void update1(int L,int R,int p,int pl,int pr,int d)
    {
        if(L<=pl&&R>=pr)
        {
            addtag(p,pl,pr,d);
            return ;
        }
        push_down_mulity(p,pl,pr);
        push_down_add(p,pl,pr);
        int mid=(pl+pr)>>1;
        if(L<=mid)
        {
            update1(L,R,ls(p),pl,mid,d);
        }
        if(R>mid)
        {
            update1(L,R,rs(p),mid+1,pr,d);
        }
        push_up(p);
    }

    void update2(int L,int R,int p,int pl,int pr,int d)
    {
        if(L<=pl&&R>=pr)
        {
            multitag(p,pl,pr,d);
            return ;
        }
        push_down_add(p,pl,pr);
        push_down_mulity(p,pl,pr);
        int mid=(pl+pr)>>1;
        if(L<=mid)
        {
            update2(L,R,ls(p),pl,mid,d);
        }
        if(R>mid)
        {
            update2(L,R,rs(p),mid+1,pr,d);
        }
        push_up(p);
    }
    
    int query(int L,int R,int p,int pl,int pr)
    {
        if(L<=pl&&R>=pr)
        {
            return tree[p]%m;
        }
        push_down_mulity(p,pl,pr);
        push_down_add(p,pl,pr);
        int res=0;
        int mid=(pl+pr)>>1;
        if(L<=mid) res+=query(L,R,ls(p),pl,mid),res%=m;
        if(R>mid) res+=query(L,R,rs(p),mid+1,pr), res%=m;
        return res%m;
    }

};

signed main()
{
    int q;
    cin>>n>>q>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    segmentTree T(n);
    T.build(1,1,n);

    while(q--)
    {
        int j;
        cin>>j;
        if(j==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            T.update2(x,y,1,1,n,k);
        }
        else if(j==2)
        {
            int x,y,k;
            cin>>x>>y>>k;
            T.update1(x,y,1,1,n,k);
        }
        else 
        {
            int x,y;
            cin>>x>>y;
            cout<<T.query(x,y,1,1,n)%m<<'\n';
        }
    }
}
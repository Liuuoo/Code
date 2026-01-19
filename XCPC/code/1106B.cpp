#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node 
{
    int cnt;
    int value;
    int index;
};
struct D
{
    bool operator()(const Node &i,const Node &j) const
    {
        if(i.value!=j.value) return i.value<j.value;
        else return i.index<j.index;
    }
};
signed main()
{
    vector<Node> a;
    multiset<Node,D> S;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        a.push_back({c,0,i+1});
    }
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        a[i].value=c;
    }
    map<int,int> M;
    for(int i=0;i<n;i++)
    {
        S.insert(a[i]);
        M[a[i].index]=a[i].value;
    }
    S.insert({0,INT64_MAX,INT64_MAX});

    while(m--)
    {
        int sum=0;
        int k,c;
        cin>>k>>c;
        Node it={0,M[k],k};
        auto lower=*S.lower_bound(it);
        if(lower.cnt>c&&lower.index==k)
        {
            sum+=lower.value*c;
            S.erase(S.find(lower));
            lower.cnt-=c;
            S.insert(lower);
        }
        else
        {
            if(lower.index==k)
            {
                S.erase(S.find(lower));
                sum+=lower.value*lower.cnt;
                c-=lower.cnt;
            }
            while(c>0&&S.size()>1)
            {
                auto up=*S.begin();
                if(up.cnt>c)
                {
                    sum+=up.value*c;
                    S.erase(S.find(up));
                    up.cnt-=c;
                    S.insert(up);
                    c=0;
                }
                else
                {
                    sum+=up.value*up.cnt;
                    c-=up.cnt;
                    S.erase(S.find(up));
                }
            }
            if(c!=0) sum=0;
        }
        cout<<sum<<'\n';
    }
}
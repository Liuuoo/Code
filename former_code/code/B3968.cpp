#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int a,b,c;
    bool operator<(const Node &other) const
    {
        if(a+b+c!=other.a+other.b+other.c) return a+b+c>other.a+other.b+other.c;
        else if(a+b!=other.a+other.b) return a+b>other.a+other.b;
        else if(max(a,b)!=max(other.a,other.b)) return max(a,b)>max(other.a,other.b);
    }
};

map<Node,int>M;

int main()
{
    int n;
    cin>>n;
    vector<Node>vec(n+1);
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        M[{a,b,c}]++;
        vec[i]={a,b,c};
    }

    int addrk=1;
    for(auto &x:M) 
    {
        int tmp=x.second; 
        x.second=addrk;
        addrk+=tmp;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<M[vec[i]]<<'\n';
    }
}
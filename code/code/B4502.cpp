#include<bits/stdc++.h>
using namespace std;

struct Node
{
    vector<int> vec;
    int sum;
    int id;
};

bool cmp(Node a,Node b)
{
    if(a.sum!=b.sum) return a.sum<b.sum;
    else if(a.vec.back()!=b.vec.back())
    {
        return a.vec.back()<b.vec.back();
    }
    else if(a.vec.front()<b.vec.front()) 
    {
        return a.vec.front()<b.vec.front();
    }
    else 
    {
        return a.id<b.id;
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    Node vec[n];
    for(int i=0;i<n;i++)
    {
        vec[i].id=i+1;
        vec[i].sum=0;
        for(int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            vec[i].vec.push_back(x);
            vec[i].sum+=x;
        }
        sort(vec[i].vec.begin(),vec[i].vec.end());
    }
    sort(vec,vec+n,cmp);
    for(auto x: vec) cout<<x.id<<" ";
}
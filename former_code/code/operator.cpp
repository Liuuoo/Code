#include<bits/stdc++.h>
using namespace std;

struct D
{
    bool operator()(int a,int b)
    {
        return a<b;
    }
};

priority_queue<int,vector<int>,D>pq;

int main()
{
    vector<int> vec={1,3,1,5,3,7,2};
    set<int,D>S;

    for(auto x:vec)
    {
        pq.push(x);
        S.insert(x);
    }

    while(!pq.empty())
    {
        int fr=pq.top();
        cout<<fr<<" ";
        pq.pop();
    }
    cout<<"\n";
    for(auto x:S) cout<<x<<" ";
}
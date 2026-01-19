#include<bits/stdc++.h>
using namespace std;
vector<string>vec1;
vector<string>vec2;
set<string>S;
set<string>stand;

bool jud(int x)
{
    int i=0;
    int j=0;
    queue<string>q;
    map<string,int> m;
    int cnt=0;
    while(1)
    {
        string now=vec2[j];
        if(j-i<x)
        {
            q.push(now);
            j++;
            if(stand.find(now)!=stand.end())
            {
                if(m[now]==0) cnt++;
                m[now]++;
            }
        }
        else {
            string p=q.front();
            if(stand.find(p)!=stand.end())
            {
                m[p]--;
                if(m[p]==0) cnt--;
            }
            if(stand.find(now)!=stand.end())
            {
                if(m[now]==0) cnt++;
                m[now]++;
            }
            q.pop();
            q.push(now);
            i++;
            j++;
        }
        if(cnt==stand.size()) return true;
        if(j==vec2.size()) return false;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        vec1.push_back(s);
        S.insert(s);
    }
    int m;
    cin>>m;
    int cnt=0;
    while(m--)
    {
        string s;
        cin>>s;
        vec2.push_back(s);
        if(S.find(s)!=S.end())
        {
            cnt++;
            S.erase(s);
            stand.insert(s);
        }
    }
    if(stand.size()==0) 
    {
        cout<<0<<"\n"<<0;
        return 0;
    }
    int l=0,r=vec2.size();
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(jud(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<stand.size()<<"\n"<<l;
}
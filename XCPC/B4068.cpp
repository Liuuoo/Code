#include<bits/stdc++.h> 
using namespace std;
vector<int> vec;

bool fid(int n)
{
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]==n)return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vec.push_back(1);
    for(int i=1;i<n;i++)
    {
        int del=vec[i-1]-(i+1);
        // cout<<del<<"\n";
        if(del<=0) vec.push_back(vec[i-1]+i+1);
        else 
        {
            if(!fid(del)) vec.push_back(del);
            else vec.push_back(vec[i-1]+i+1);
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
}
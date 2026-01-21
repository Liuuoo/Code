#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> M;
    vector<int> T;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        M.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        T.push_back(x);
    }
    sort(M.begin(),M.end());
    sort(T.begin(),T.end());
    /*
    1 3 5
    2 4 6
    */
    int ans=0;
    int idx=0;
    for(int i=0;i<n;i++)
    {
        while(M[idx]<T[i])
        {
            idx++;
        }
    }
}
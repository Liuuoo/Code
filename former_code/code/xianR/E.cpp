#include<bits/stdc++.h>
using namespace std;
const int N=5100;
vector<int>g[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<-n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char c;
            cin>>c;
            if(c=='1') g[i].push_back(j);
        }
    }
    
}
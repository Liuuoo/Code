#include<bits/stdc++.h>
using namespace std;
string s="BESIGOM";
const int N=550;
int arr[7];
bool vis[7][7];
long long ans=0;
map<pair<char,int>,int>S;
map<char,set<int>>M;
void dfs(int x)
{
    if(x==7)
    {
        int _1=arr[0]+arr[1]*2+arr[2]*2+arr[3];
        int _2=arr[4]+arr[5]+arr[1]+arr[2];
        int _3=arr[6]+arr[5]*2;
        if(_1%7==0||_2%7==0||_3%7==0)
        {
            long long tmp=1;
            for(int i=0;i<7;i++)
            {
                tmp*=(long long)S[{s[i],arr[i]}];
            }
            ans+=tmp;
        }
        return;
    }
    for(auto it:M[s[x]])
    {
        if(!vis[x][it])
        {
            vis[x][it]=true;
            arr[x]=it;
            dfs(x+1);
            vis[x][it]=false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c;int x;
        cin>>c>>x;
        S[{c,(x%7+7)%7}]++;
        M[c].insert((x%7+7)%7);
    }
    dfs(0);
    cout<<ans;
}
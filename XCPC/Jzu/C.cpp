#include<bits/stdc++.h>
using namespace std;
const int N=30;
int box[N][N];
bool vis[N];
int arr[N];
bool jud;
void dfs1(int n,vector<set<int>> S, int x)
{
    if(x==n)
    {
        // for(int i=0;i<n;i++) cout<< arr[i]<<" "; cout<<"\n";
        set<int> t1;
        for(auto x:S[arr[0]]) t1.insert(x);
        if(t1.empty()) {
            jud=true;
            return;
        }

        for(int i=1;i<n;i++)
        {
            set<int> tmp=S[arr[i]];
            if(tmp.empty()) {
                jud=true;
                return;
            }
            for(auto x=t1.begin();x!=t1.end();)
            {
                if(tmp.find(*x)==tmp.end())
                {
                    x=t1.erase(x);
                }
                else x++;
            }
        }
        if(t1.empty()) jud=true;
        return;
    }

    for(int i=0;i<S.size();i++)
    {
        if(!vis[i])
        {
            arr[x]=i;
            vis[i]=true;
            dfs1(n,S,x+1);
            dfs1(n,S,x+1);
            vis[i]=false;
        }
    }
}


void dfs2(int n,vector<set<int>> S, int x)
{
    // 哪些组不选
    if(x==n)
    {
        // for(int i=0;i<n;i++) cout<< arr[i]<<" "; cout<<"\n";
        set<int> t1;

        vector<set<int>> S2;
        map<int,bool> brr;
        for(int i=0;i<n;i++) brr[arr[i]]=true;
        for(int i=0;i<S.size();i++)
        {
            if(!brr[i]) S2.push_back(S[i]);
        }

        t1=S2[0];

        for(auto x:S2[arr[0]]) t1.insert(x);
        if(t1.empty()) {
            jud=true;
            return;
        }

        for(int i=1;i<S2.size();i++)
        {
            set<int> tmp=S2[arr[i]];
            if(tmp.empty()) {
                jud=true;
                return;
            }
            for(auto x=t1.begin();x!=t1.end();)
            {
                if(tmp.find(*x)==tmp.end())
                {
                    x=t1.erase(x);
                }
                else x++;
            }
        }
        if(t1.empty()) jud=true;
        return;
    }

    for(int i=0;i<S.size();i++)
    {
        if(!vis[i])
        {
            arr[x]=i;
            vis[i]=true;
            dfs1(n,S,x+1);
            dfs1(n,S,x+1);
            vis[i]=false;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            box[i][j]=x;
        }
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        vector<set<int>> S;
        for(int j=1;j<=m;j++)
        {
            set<int> tmp;
            for(int k=1;k<=n;k++)
            {
                if(k==i) continue;
                if(box[k][j]==box[i][j])
                {
                    tmp.insert(k);
                }
            }
            S.push_back(tmp);
        }
        jud=false;
        for(int cnt=1;cnt<=10;cnt++)
        {
            memset(vis,false,sizeof(vis));
            dfs1(cnt,S,0);
            if(jud) 
            {
                cout<<cnt<<" ";
                break;
            }
        }
        if(!jud) 
        {
            if(n<=10) 
            {
                cout<<"-1 ";
            }
            else 
            {
                for(int cnt=1;cnt<=10;cnt++)
                {
                    memset(vis,false,sizeof(vis));
                    dfs2(cnt,S,0);
                    if(jud) 
                    {
                        cout<<cnt<<" ";
                        break;
                    }
                }
                if(!jud) 
                {
                    cout<<"-1 ";
                }
            }
        }
    }
}
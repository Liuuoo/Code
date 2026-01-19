#include<bits/stdc++.h>
using namespace std;

int n,c;
set<int> vl,vc; //vl-亮
int a[4]; //0-偶数 1-奇数
vector<string>ans;
void dfs(int x)
{
    if(x==4)
    {
        int odd=0;
        for(int i=0;i<4;i++)
        {   
            if(a[i]==1)
            {   
                odd++;
            }
        }
        if((c-odd)%2!=0||odd>c) return; //不满足数量要求
        else 
        {
            string res;
            for(int i=1;i<=n;i++)
            {
                int cnt=a[0];
                if(i%2==0) cnt+=a[1];
                if(i%2==1) cnt+=a[2];
                if(i%3==1) cnt+=a[3];
                if(cnt%2==0) //偶数次
                {
                    if(vc.find(i)!=vc.end())
                    {
                        return;
                    }
                    res+='1';
                }
                else //奇数次
                {
                    if(vl.find(i)!=vl.end())
                    {
                        return;
                    }
                    res+='0';
                }
            }
            ans.push_back(res);
            return;
        }
    }
    a[x]=0;
    dfs(x+1);
    a[x]=1;
    dfs(x+1);
}

int main()
{
    cin>>n>>c;
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        vl.insert(x);
    }
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        vc.insert(x);
    }
    dfs(0);
    sort(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<"\n";
    if(!ans.size()) cout<<"IMPOSSIBLE";
}
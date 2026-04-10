#include<bits/stdc++.h>
using namespace std;
map<pair<int16_t,int16_t>,int8_t> box;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int16_t,int16_t>> vec;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='#')
            {
                box[{i,j}]=1;
                vec.push_back({i,j});
            }
        }
    }
    int ans=0;
    for(auto [x,y]:vec)
    {
        for(int i=-k;i<=k;i++)
        {
            for(int j=-k;j<=k;j++)
            {
                int xx=x+i,yy=y+j;
                if(abs(xx-x)+abs(yy-y)>k) continue;
                if(box[{xx,yy}]==0)
                {
                    ans++;
                    box[{xx,yy}]=1;
                }
            }
        }
    }
    cout<<ans;
}
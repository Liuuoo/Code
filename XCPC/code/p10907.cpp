#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,pair<int,int>>> vec;


pair<double,double> calc(int x1,int y1,int x2,int y2)
{
    double ans=(y2-y1)*1.0/(x2-x1)*1.0;
    double b=y1*1.0-ans*x1*1.0;
    return {ans,b};
}


bool jud(int a,int b)
{
    pair<int,int>l11=vec[a].first;
    int x1=l11.first;
    int y1=l11.second;

    pair<int,int>l12=vec[a].second;
    int x2=l12.first;
    int y2=l12.second;

    pair<int,int>l21=vec[b].first;
    int u1=l21.first;
    int v1=l21.second;

    pair<int,int>l22=vec[b].second;
    int u2=l22.first;
    int v2=l22.second;

    pair<double, double> p1=calc(x1,y1,x2,y2);
    pair<double, double> p2=calc(u1,v1,u2,v2);

    double k1=p1.first;
    double b1=p1.second;

    double k2=p2.first;
    double b2=p2.second;

    double jx=(b2-b1)/(k1-k2);
    double jy=k1*(jx)+b1;
    // cout<<jx<<" "<<jy<<'\n';
    if(jx==(int)jx && jy==(int)jy) 
    {
        
        if(jx<min(x1,x2)||jx>max(x1,x2)||jy<min(y1,y2)||jy>max(y1,y2))
        {
            return false;
        }
        else return true;
    }
    else return false;
}

int main() 
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        vec.push_back({{x,y},{u,v}});
    }
    // jud(0,1);
    int ans=0;
    for(int i=0;i<vec.size();i++)
    {
        for(int j=vec.size()-1;j>i;j--)
        {
            ans+=jud(i,j);
            //if(jud(i,j)) cout<<i<<" "<<j<<'\n';
        }
    }
    cout<<ans;
}

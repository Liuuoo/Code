#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
vector<pair<int,int>> vec;

double calc(int i,int j)
{
    pair<int,int>p1=vec[i];
    pair<int,int>p2=vec[j];
    int delx=p1.first-p2.first;
    int dely=p1.second-p2.second;
    return (sqrt(delx*delx*1.0+dely*dely*1.0));
}

bool jud(double l1,double l2,double l3)
{
    double arr[3]={l1,l2,l3};
    sort(arr,arr+3);
    double mi=arr[0];
    double md=arr[1];
    double ma=arr[2];
    if(mi+md<=ma) return false;
    else return true;
}

signed main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                set<double>se;
                double l1,l2,l3;
                l1=calc(i,j);
                l2=calc(i,k);
                l3=calc(j,k);
                if(jud(l1,l2,l3))
                {
                    se.insert(l1);
                    se.insert(l2);
                    se.insert(l3);
                    //cout<<l1<<" "<<l2<<' '<<l3<<'\n';
                    if(se.size()<=2) 
                    {
                        //cout<<i<<" "<<j<<" "<<k<<'\n';
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
}
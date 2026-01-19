#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int t;
    string p,v;
};

bool cmp(Node i, Node j)
{
    return i.t<j.t;
}

void solve()
{
    vector<Node>unkon;
    set<string> acS;
    set<string> tyS;
    int acT=0;
    map<string,int> rjT;
    int n,a,b;
    cin>>n>>a>>b;
    int s;
    cin>>s;
    while(s--)
    {
        int t; string p,v;
        cin>>t>>p>>v;
        if(v!="pd")
        {
            if(v=="ac")
            {
                if(acS.find(p)==acS.end())
                {
                    acS.insert(p);
                    acT+=t;
                    acT+=rjT[p];
                }
            }
            else if(v=="rj")
            {
                if(acS.find(p)==acS.end())
                {
                    rjT[p]+=20;
                }
            }
        }
        else 
        {
            if(acS.find(p)!=acS.end()) continue;
            if(tyS.find(p)!=tyS.end()) continue;
            else 
            {
                tyS.insert(p);
                int allv=t+rjT[p];
                unkon.push_back({allv,p,v});
            }
        }
    }
    if(acS.size()>a || (acS.size()==a&&acT<b) )
    {
        cout<<"0\n";
        return;
    }
    else 
    {
        int accnt=acS.size();
        // cout<<accnt<<" "<<acT<<"\n";
        sort(unkon.begin(),unkon.end(),cmp);
        int extim=acT;
        for(int i=0;i<unkon.size();i++)
        {
            extim+=unkon[i].t;
            if(accnt+i+1==a)
            {
                if(extim<b) {
                    cout<<i+1<<'\n';
                    return;
                }
            }
            else if(accnt+i+1>a)
            {
                cout<<i+1<<'\n';
                return;
            }
        }
        cout<<-1<<'\n';
        return;
    }
}
signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}

// 1
//  11 6 900
//  13
//  11 C ac
//  34 J ac
//  52 D rj
//  61 D ac
//  193 A ac
//  207 A ac
//  220 G ac
//  245 A pd
//  247 A pd
//  262 H pd
//  299 A pd
//  299 C pd
//  299 K pd
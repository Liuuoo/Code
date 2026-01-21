#include<bits/stdc++.h>
using namespace std;
int ss,t,w;
int cnt=0;
string s;
bool vis[123];

signed main()
{
    cin>>ss>>t>>w;
    cin>>s;
    int cnt=0;
    int mx='a'+t-1;
    int mi='a'+ss-1;
    // cout<<mx<<" "<<mi<<'\n';
    string ms;
    ms.resize(s.size()+1);
    for(int i=0;i<s.size();i++)
    {
        ms[i]=char(mx-i);
    }
    reverse(ms.begin(),ms.begin()+s.size());
    // cout<<ms<<'\n';
    while(cnt<5)
    {
        int i=s.size()-1;
        while(s[i]<ms[i])
        {
            s[i]=s[i]+1;
            cout<<s<<'\n';
            cnt++;
            if(cnt>=5) return 0;
        }
        while(i!=-1&&s[i]>=ms[i])
        {
            i--;
        }
        if(i==-1) break;
        s[i]=s[i]+1;
        for(int j=i+1;j<s.size();j++)
        {
            s[j]=s[j-1]+1;
        }
        cout<<s<<"\n";
        cnt++;
    }
}
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]!=s.back())
    {
        cout<<"empty\n";
    }
    else 
    {
        if(s[0]=='0') //0
        {
            int i=0;
            int len=INT_MAX;
            while(i<n)
            {
                if(s[i]=='1')
                {
                    int tmp=i;
                    i++;
                    while(s[i]=='0'&&i<n)
                    {
                        i++;
                    }
                    if(i<n) 
                    {
                        len=min(len,i-tmp+1);
                    }
                    else break;
                }
                else 
                {
                    i++;
                }
            }
            if(len==INT_MAX) 
            {
                bool jud=false;
                for(int i=0;i<n;i++)
                {
                    if(s[i]=='1')
                    {
                        jud=true;
                        len=min(i,n-(i+1));
                        // cout<<min(i+1,n-(i+1+1))<<'\n';
                        for(int j=0;j<len;j++) cout<<"0";
                        cout<<'\n';
                    }
                }
                if(!jud) cout<<s<<'\n';
            }
            else //1
            {
                // cout<<len<<"\n";
                if(len<=2) cout<<"empty\n";
                else 
                {
                    int cnt1=0,cnt2=0;
                    for(int i=0;i<n;i++)
                    {if(s[i]=='1') break;
                        cnt1++;
                        
                    }
                    for(int i=n-1;i>=0;i--)
                    {if(s[i]=='1') break;
                        cnt2++;
                        
                    }
                    int las=min(min(cnt1,cnt2),len-2);
                    for(int j=0;j<las;j++) cout<<"0";
                    cout<<'\n';
                }
            }
        }
        else // 1
        {
            int i=0;
            int len=INT_MAX;
            while(i<n)
            {
                if(s[i]=='0')
                {
                    int tmp=i;
                    i++;
                    while(s[i]=='1'&&i<n)
                    {
                        i++;
                    }
                    if(i<n) 
                    {
                        len=min(len,i-tmp+1);
                    }
                    else break;
                }
                else 
                {
                    i++;
                }
            }
            if(len==INT_MAX) 
            {
                bool jud=false;
                for(int i=0;i<n;i++)
                {
                    if(s[i]=='0')
                    {
                        jud=true;
                        // cout<<min(i+1,n-(i+1+1))<<'\n';
                        int len=min(i,n-(i+1));
                        for(int j=0;j<len;j++) cout<<"1";
                        cout<<'\n';
                    }
                }
                if(!jud) cout<<s<<'\n';
            }
            else 
            {
                // cout<<len<<"\n";
                if(len<=2) cout<<"empty\n";
                else 
                {   
                    int cnt1=0,cnt2=0;
                    for(int i=0;i<n;i++)
                    {if(s[i]=='0') break;
                        cnt1++;
                        
                    }
                    for(int i=n-1;i>=0;i--)
                    {if(s[i]=='0') break;
                        cnt2++;
                        
                    }
                    int las=min(min(cnt1,cnt2),len-2);
                    for(int j=0;j<las;j++) cout<<"1";
                    cout<<'\n';
                }
            }
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
int jud=1;
int fsum=0;
int sum=0;
void calc(string s)
{
    int i=0,j=0;
    while(i<s.size())
    {
        j=i;
        string tmp;
        if(j==0&&s[j]!='-')
        {
            tmp="+";
        }
        else if(j==0&&s[j]=='-')
        {
            tmp="-";
            j++;
        }
        else if(s[j]=='+')
        {
            tmp="+";
            j++;
        }
        else if(s[j]=='-')
        {
            tmp="-";
            j++;
        }
        while(j<s.size()&&isdigit(s[j]))
        {
            tmp+=s[j];
            j++;
        }

        if(j>=s.size()) 
        {
            sum+=stoi(tmp)*jud;
            break;
        }
        else if(tmp.size()==1) 
        {
            if(isalpha(s[j]))
            {
                if(tmp=="-") fsum+=-1*jud;
                else fsum+=1*jud;
                i=j+1;
            }
            else i=j;
        }
        else if(isalpha(s[j]))
        {
            fsum+=stoi(tmp)*jud;
            i=j+1;
        }
        else 
        {
            sum+=stoi(tmp)*jud;
            i=j;
        }
    }
}

signed main()
{
    string s;
    cin>>s;
    char c;
    string s1,s2;
    int t;
    for(int i=0;i<s.size();i++)
    {
        if(isalpha(s[i]) ) c=s[i];
        if(s[i]=='=') 
        {
            t=i;
            break;
        }
        s1+=s[i];
    }
    for(int i=t+1;i<s.size();i++)
    {
        if(isalpha(s[i]) ) c=s[i];
        s2+=s[i];
    }

    calc(s1);
    jud=-1;
    calc(s2);
    double ans=sum*(-1.0)/(fsum)*(1.0);
    printf("%c=%.3lf",c,ans);
}
#include<bits/stdc++.h>
using namespace std;
int n;
string s;

int calc()
{
    int sum=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='1') sum+=i;
    }
    return sum;
}

vector<int> calc2()
{
    vector<int> vec(s.size()+1);
    vec[s.size()-1]=0;
    for(int i=s.size()-2;i>=0;i--)
    {
        vec[i]=vec[i+1]+(s[i+1]=='1');
    }
    return vec;
}

bool jud4(int x)
{
    if(x%(n+1)==0||x==0) 
    {
        return 1;
    }
    return 0;
}

int jud1(int x)
{
    for(int i=1;i<s.size();i++) 
    {
        if(s[i]=='1') 
        {
            if(jud4(x-i)) return i;
        }
    }
    return 0;
}

int jud2(int x,vector<int>vec)
{
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            if(jud4(x-vec[i])) return i;
        }
        else 
        {
            if(jud4(x-vec[i]-i)) 
            {
                if(i+1==s.size()||s[i+1]=='1')
                    return i;
                else 
                {
                    if(jud4(x-vec[i+1])) return i+1;
                    else return i;
                }
            }
        }
    }
    return 0;
}

pair<int,int> jud3(int x,vector<int> vec)
{
    // 0
    for(int i=1;i<s.size();i++)
    {
        int nx1,nx2;
        if(s[i]=='0')
        {
            if(jud4(x+vec[i])) return {0,i};
            if(jud4(x+vec[i]+i)) return {1,i};
        }
        else 
        {
            if(jud4(x+vec[i]+1)) return {0,i};
            if(jud4(x+vec[i]+i+1)) return {1,i};
        }
    }
    if(jud4(x))  return {0,n};
    if(jud4(x+n))  return {1,n};
    return {-1,-1};
}

pair<int,int> jud(int sum,vector<int>pre_cnt)
{
    if(s.size()!=n+1) return {-1,-1};
    if(jud4(sum)) return {4,-1};
    if(jud1(sum)) return {1,jud1(sum)};
    return {-1,-1};
}

int main()
{
    srand(time(0));
    cin>>n;
    n=5;
    while(1)
    {
        cin >> s;
        // s="";
        // for(int i=0;i<n-1;i++) s+=rand()%2+'0';
        // cout<<s<<'\n';
        s='$'+s;
        int sum=calc();
        vector<int> pre_cnt=calc2();
        pair<int,int>p=jud(sum, pre_cnt);
        if(p.first!=-1)
        {
            if(p.first==4) 
            {
                for(int i=1;i<s.size();i++) cout<<s[i];
            }
            else 
            {
                for(int i=1;i<s.size();i++)
                {
                    if(i==p.second) cout<<0;
                    else cout<<s[i];
                }
            }
        }
        else if(s.size()==n+2)
        {
            string tmp;
            int x=jud2(sum,pre_cnt);
            if(x!=0)
            {
                for(int i=1;i<s.size();i++)
                {
                    if(i==x) continue;
                    // cout<<s[i];
                    tmp+=s[i];
                }
                
            } 
            // else cout<<"-1";
        }
        else if(s.size()==n){
            string tmp;
            p=jud3(sum,pre_cnt);
            if(p.first!=-1)
            {
                for(int i=1;i<s.size();i++)
                {
                    if(i==p.second) 
                    {
                        // cout<<p.first;
                        tmp+=p.first+'0';
                    }
                    // cout<<s[i];
                    tmp+=s[i];
                }
                if(p.second==n) 
                {
                    // cout<<p.first;
                    tmp+=p.first+'0';
                }
                int tmps=0;
                for(int i=0;i<tmp.size();i++) if(tmp[i]=='1') tmps+=i+1;
                if(!jud4(tmps)) 
                {
                    cout<<tmps<<" "<<s<<'\n';
                    cout<<tmp;
                    break;
                }
            }
            else 
            {
                // cout<<"-1";
            }
        }
        // cout<<" "<<p.first<<" ";
        else cout<<-1;
        // cout<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
map<string,vector<set<string>> > M;
vector<string> name;
vector<string> days={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int n,m;
int ext=0;
string sub(int l,int r,string &s)
{
    string res;
    for(int i=l;i<=r;i++) res+=s[i];
    return res;
}

bool dayisin(string &s)
{
    return (s=="Monday"||s=="Tuesday"||s=="Wednesday"||s=="Thursday"||s=="Friday"||s=="Saturday"||s=="Sunday");
}

pair<int,string> calc(string &s)
{
    s+=" ";
    string arr[260];
    int len=0;
    string tmp; 
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' ') tmp+=s[i];
        else 
        {
            if(tmp.size()==0) continue;
            else 
            {
                arr[len++]=tmp;
                tmp="";
            }
        }
    }
    if(len==3||len==4)
    {
        if(len==3)
        {
            if(arr[0]=="I"&&arr[1]=="am"&&arr[2]=="guilty.") return {0,"1"};
            else if(arr[1]=="is"&&arr[2]=="guilty.") return {2,arr[0]};
            else if(arr[0]=="Today"&&arr[1]=="is")
            {
                arr[2].pop_back();
                if(dayisin(arr[2])) return {4,arr[2]};
                else return {-1,"1"};
            }
            else return {-1,"1"};
        }
        else 
        {
            if(arr[0]=="I"&&arr[1]=="am"&&arr[2]=="not"&&arr[3]=="guilty.") return {1,"1"};
            else if(arr[1]=="is"&&arr[2]=="not"&&arr[3]=="guilty.") return {3,arr[0]};
            else return {-1,"1"};
        }
    }
    else return {-1,"1"};
}

bool jud(string &stand)
{
    int cntd=0;
    map<string,int> d;
    set<string> t;
    set<string> f;
    string day;
    set<string> fakeday;
    for(auto x:name)
    {
        if(!M[x][0].empty())
        {
            if(x==stand) t.insert(x);
            else f.insert(x);
        }
        if(!M[x][1].empty())
        {
            if(x==stand) 
            {
                if(t.find(x)!=t.end()) return false;
                f.insert(x);
            }   
            else 
            {
                if(f.find(x)!=f.end()) return false;
                t.insert(x);
            }
        }
        if(!M[x][2].empty())
        {
            int talk=-1;
            if(t.find(x)!=t.end()) talk=1;
            if(f.find(x)!=f.end()) talk=0;
            if(talk==1)
            {
                if(M[x][2].size()!=1) return false;
                string r=*M[x][2].begin();
                if(r!=stand) return false;
            }
            else if(talk==0)
            {
                if(M[x][2].find(stand)!=M[x][2].end()) return false;
            }
            else 
            {
                if(M[x][2].size()>1) 
                {
                    for(auto r:M[x][2])
                    {
                        if(r==stand) return false;
                    }
                    f.insert(x);
                }
                else 
                {
                    if(*M[x][2].begin()==stand) t.insert(x);
                    else f.insert(x);
                }
            }
        }
        if(!M[x][3].empty())
        {
            int talk=-1;
            if(t.find(x)!=t.end()) talk=1;
            if(f.find(x)!=f.end()) talk=0;
            if(talk==1)
            {
                for(auto r:M[x][3])
                {
                    if(r==stand) return false;
                }
            }
            else if(talk==0)
            {
                if(M[x][3].size()!=1) return false;
                string r=*M[x][3].begin();
                if(r!=stand) return false;
            }
            else 
            {
                if(M[x][3].find(stand)==M[x][3].end())
                {
                    t.insert(x);
                }
                else 
                {
                    if(M[x][3].size()!=1) return false;
                    else 
                    {
                        f.insert(x);
                    }
                }
            }
        }
        if(!M[x][4].empty())
        {
            if(M[x][4].size()!=1) return false;
            cntd++;
            int talk=-1;
            if(t.find(x)!=t.end()) talk=1;
            if(f.find(x)!=f.end()) talk=0;
            if(talk==1)
            {
                if(M[x][4].size()!=1) return false;
                string newday=*M[x][4].begin();
                if(fakeday.find(newday)!=fakeday.end()) return false;

                if(day!="")
                {
                    if(day!=newday) return false;
                }
                else 
                {
                    day=newday;
                }
            }
            else if(talk==0)
            {
                for(auto newday: M[x][4])
                {
                    if(newday==day) return false;
                    else fakeday.insert(newday);
                }
            }
            else 
            {
                d[*M[x][4].begin()]++;
                bool jud1=false; // 假话
                bool jud2=false;
                if(M[x][4].size()!=1) jud1=true;
                for(auto newday: M[x][4])
                {
                    if(fakeday.find(newday)!=fakeday.end()) 
                    {
                        jud1=true;
                        f.insert(x);
                    }
                    if(newday==day) 
                    {
                        jud2=true;
                        t.insert(x);
                    }
                }
                if(jud1&&jud2) return false;
            }
        }
    }
    if(day!="")
    {
        string ds=day;
        set<string>tt;
        set<string>ff;
        for(auto x:t) tt.insert(x);
        for(auto x:f) ff.insert(x);
        for(auto x:name) 
        {
            if(!M[x][4].empty())
            {
                auto it=*M[x][4].begin();
                if(it==ds)
                {
                    tt.insert(x);
                }
                else ff.insert(x);
            }
        }
        if(ff.size()==n||(ff.size()<n&&ff.size()+ext>=n)) return true;
    }
    else {
        for(auto ds:days)
        {
            set<string>tt;
            set<string>ff;
            for(auto x:t) tt.insert(x);
            for(auto x:f) ff.insert(x);
            for(auto x:name) 
            for(auto x:name) 
            {
                if(!M[x][4].empty())
                {
                    auto it=*M[x][4].begin();
                    if(it==ds)
                    {
                        tt.insert(x);
                    }
                    else ff.insert(x);
                }
            }
            if(ff.size()==n||(ff.size()<n&&ff.size()+ext>=n)) return true;
        }
    }
    return false;
}

int main()
{
    // freopen("P1039_1.in","r",stdin);
    int p;
    cin>>m>>n>>p;
    getchar();
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        name.push_back(s);
        M[s].resize(5);
    }
    getchar();
    while(p--)
    {
        string tmp1;
        cin>>tmp1;
        tmp1.pop_back();
        string tmp2;
        while(tmp2.size()<=1) getline(cin,tmp2);
        while(tmp2.back()=='\r'||tmp2.back()=='\n')tmp2.pop_back();
        auto p=calc(tmp2);
        if(p.first==-1) continue;
        M[tmp1][p.first].insert(p.second);
    }
    for(auto x:name)
    {
        int jud=false;
        for(int i=0;i<5;i++)
        {
            if(M[x][i].size()!=0) jud=true; 
        }
        if(!jud) ext++;
    }
    vector<string> ans;
    for(auto x:name) // x为凶手
    {
        if(jud(x)) ans.push_back(x);
    }
    if(ans.size()==0) cout<<"Impossible";
    else if(ans.size()==1) cout<<ans[0];
    else cout<<"Cannot Determine";
}
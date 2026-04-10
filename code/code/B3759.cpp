#include<bits/stdc++.h>
using namespace std;

void solve()
{
    // 改题目n很长，且一定是易于人类阅读的文本，所以尝试利用一些关键单词判断。
    int n;
    cin>>n;
    vector<string> vec;
    bool jud=false;
    for(int i=0;i<n;i++)
    {   
        string s;
        cin>>s;
        if(s.size()>=7) jud=true;
        vec.push_back(s);
    }
    
    if(jud||find(vec.begin(),vec.end(),"A")!=vec.end() || find(vec.begin(),vec.end(),"I")!=vec.end() || find(vec.begin(),vec.end(),"it")!=vec.end() || find(vec.begin(),vec.end(),"is")!=vec.end() || find(vec.begin(),vec.end(),"and")!=vec.end() || find(vec.begin(),vec.end(),"")!=vec.end())
    {
        cout<<"English\n";
        return;
    }
    {
        cout<<"Pinyin\n";
        return;
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
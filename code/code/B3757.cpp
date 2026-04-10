#include<bits/stdc++.h>
using namespace std;
int main()
{
    // int n;
    // cin>>n;
    // string out="THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG";
    // map<char,string >M;
    // for(int i=0;i<n;i++)
    // {
    //     string s;
    //     cin>>s;
    //     M[out[i]]=s;
    // }
    // for(auto x:M)
    // {
    //     cout<<x.second<<"\n";
    // }

    string table[]=
    {
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--.."
    };
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int idx=find(table,table+26,s)-table;
        cout<<(char)(idx+'A');
    }

}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int son=0;
    int mon=0;
    int i=0,j=0;
    while(1)
    {
        string tmp;
        while(isdigit(s[i]))
        {
            tmp+=s[i];
            i++;
        }
        son+=stoi(tmp);
        while(!isdigit(s[i])) i++;

        

    }
}
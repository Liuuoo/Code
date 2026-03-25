#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int d=s1[0]-s2[0]; // d表示密文到明文需要加多少
    for(int i=0;i<s3.size();i++)
    {
        cout<<char((s3[i]-'A'+d+26)%26+'A');
    }
}
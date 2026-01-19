#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<26;i++){
        int tmp=n+i+'A';
        while(tmp>'Z') tmp-=26;
        cout<<char(tmp);
    }
}
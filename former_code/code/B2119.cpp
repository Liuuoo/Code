#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int lena=a.size();
    if(a[lena-1]=='r' && a[lena-2]=='e') a[lena-1]=a[lena-2]=' ';
    if(a[lena-1]=='y' && a[lena-2]=='l') a[lena-1]=a[lena-2]=' ';
    if(a[lena-1]=='g' && a[lena-2]=='n' && a[lena-3]=='i') a[lena-1]=a[lena-2]=a[lena-3]=' ';
    cout<<a;
    return 0;
 } 

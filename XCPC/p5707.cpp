#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,v;
    cin>>s>>v;
    int t=(s+v-1)/v+10;
    int hh=t/60;
    int mm=t%60;
    
    hh=7-hh;
    while(hh<0) hh+=24;
    
    mm=60-mm;
    if(mm==60) hh++,mm=0; 
    
    printf("%02d:%02d",hh,mm);
}
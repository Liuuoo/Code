#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    int cnt=(y+x-1)/x;
    cout<<max(n-cnt,0);
}
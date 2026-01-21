#include<bits/stdc++.h>
using namespace std;
string to_bit(int n) 
{
    string s;
    while(n)
    {
        s+=(n%2+'0');
        n/=2;
    }
    return s;
}
int main()
{
    int q;
    cin>>q;
    map<int,int> M;
    M[1]=0;
    M[3]=1;
    M[7]=1;
    M[15]=5;
    M[31]=1;
    M[63]=21;
    M[127]=1;
    M[255]=85;
    M[511]=73;
    M[1023]=341;
    M[2047]=89;
    M[4095]=1365;
    M[8191]=1;
    M[16383]=5461;
    M[32767]=4681;
    M[65535]=21845;
    M[131071]=1;
    M[262143]=87381;
    M[524287]=1;
    M[1048575]=349525;
    M[2097151]=299593;
    M[4194303]=1398101;
    M[8388607]=178481;
    M[16777215]=5592405;
    M[33554431]=1082401;
    while(q--)
    {
        int a;
        cin>>a;
        string s=to_bit(a);
        if(M[a]!=0||a==1)
        {
            cout<<M[a]<<'\n';
        }
        else 
        {
            cout<<((1<<s.size())-1)<<'\n';
        }
    }
}
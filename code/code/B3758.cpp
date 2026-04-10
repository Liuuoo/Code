#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(st.empty())
        {
            if(s[i]=='(')
            {
                st.push('(');
                cout<<'(';
            }
            else
            {
                cout<<"()";
            }
        }
        else 
        {
            if(s[i]==')'&&st.top()=='(')
            {
                st.pop();
                cout<<')';
            }
            else
            {
                st.push('(');
                cout<<'(';
            }
        }
    }
    while(!st.empty())
    {
        st.pop();
        cout<<')';
    }
}
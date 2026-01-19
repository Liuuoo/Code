#include<bits/stdc++.h>
using namespace std;

bool check(map<char, int> m) {
    for(auto x: m) {
        if(x.second%2 != 0) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    map<char, int> m;
    for(auto x: s) {
        m[x]++;
    }
    if(check(m)) cout << "YES";
    else cout << "NO";
}
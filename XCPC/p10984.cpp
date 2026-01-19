#include<bits/stdc++.h>
using namespace std;
set<string> s;

bool check(string s1, string s2) {
    for(int i = 0; i < s1.size(); i++) {
        if(s2[i] != s1[i]) {
            if(s1[i] == '1') return false;
        }
    }
    return true;
}

int main() {
    s.insert("1111110");
    s.insert("0110000");
    s.insert("1101101");
    s.insert("1111001");
    s.insert("0110011");
    s.insert("1011011");
    s.insert("1011111");
    s.insert("1110000");
    s.insert("1111111");
    s.insert("1111011");

    vector<string> vec = {
        "0000011",
        "1001011",
        "0000001",
        "0100001",
        "0101011",
        "0110110",
        "1111111",
        "0010110",
        "0101001",
        "0010110",
        "1011100",
        "0100110",
        "1010000",
        "0010011",
        "0001111",
        "0101101",
        "0110101",
        "1101010"
    };
    int ans = 1;
    for(auto x: vec) {
        int tmp = 0;
        for(auto y: s) {
            if(check(x, y)) tmp++;
        }
        ans *= tmp;
    } 
    cout << ans;
}
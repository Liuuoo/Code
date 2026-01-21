#include<bits/stdc++.h>
using namespace std;
string to_bit(int n) {
    string s = "";
    if(n == 0) return "0";
    while(n) {
        s += n % 2 + '0';
        n /= 2;
    }
    return s;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, x;
        cin >> n >> x;
        string s = to_bit(x);
        int tmp = s.size() - 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                tmp = i;
                break;
            }
        }
        
        int max_num = pow(2, tmp);
        if(n > x) {
            for(int i = 0; i <= x; i++) {
                cout << i << " ";
                n--;
            }
            for(int i = 0; i < n; i++) cout << "0 ";
            cout << '\n';
        }
        else {
            int tn = n;
            vector<int> vec;
            for(int i = 0; i < max_num; i++) {
                vec.push_back(i);
                tn--;
                if(!tn) break;
            }
            if(!tn) { 
                for(int i = 0; i < vec.size() - 1; i++) cout << vec[i] << " ";
                cout << x << '\n';
            }
            else {
                for(auto x: vec) cout << x << " ";

                for(int i = 0; i < tn; i++) cout << "0 ";
                cout << '\n';
            }
        }
    }
}
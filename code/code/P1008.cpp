#include<bits/stdc++.h>
using namespace std;

string m_to_string(int x) {
    string s = to_string(x);
    while(s.size() != 3) {
        s = "0" + s;
    }
    return s;
}

int main() {
    for(int i = 111; i <= 999; i++) {
        int j, k;
        j = i*2;
        k = i*3;
        if(k > 999) break;
        string x, y, z;
        x = m_to_string(i);
        y = m_to_string(j);
        z = m_to_string(k);
        int vis[1234] = {0};
        for(int i = 0; i < 3; i++) {
            vis[x[i]]++;
            vis[y[i]]++;
            vis[z[i]]++;
        }
        int jud = true;
        for(int i = '1'; i <= '9'; i++) {
            if(vis[i] == 0 || vis[i] > 1) jud = false;
        }
        if(!jud) continue;
        cout << i << " " << j << " " << k << '\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
const int N = 270;
string s[N];
int tmp[344] = {0};
set<int> se;

int change(char a, char b) {
    int ans = 0;
    int fr, ba;
    if(isalpha(a)) fr = a - 'A' + 10;
    else fr = a - '0';
    if(isalpha(b)) ba = b - 'A' + 10;
    else ba = b - '0';
    ans = fr * 16 + ba;
    return ans;
}

// 回转函数
pair<char, char> rechange(int x) {
    char a, b;
    if(x % 16 < 10) b = (x % 16) + '0';
    else b = x % 16 - 10 + 'A';
    x /= 16;
    if(x % 16 < 10) a = (x % 16) + '0';
    else a = (x % 16) - 10 + 'A';
    return {a, b};
}

struct Item {
    char a;
    char b;
    int cnt;
}a[N];

bool cmp(Item i, Item j) {
    if(i.cnt != j.cnt) return i.cnt > j.cnt;
    else {
        if(i.a == j.a) return i.b < j.b;
        else return i.a < j.a;
    }
}

char my_print(int x) {
    if(x < 10) return x + '0';
    else return x - 10 + 'A';
}

int main() {
    int n;
    cin >> n;
    assert(n < 23);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < s[i].size() - 1; j += 2) {
            int num = change(s[i][j], s[i][j + 1]);
            tmp[num]++;
            se.insert(num);
        }
    }
    int sum = 0;
    for(auto x: se) {
        pair<char, char> p = rechange(x);
        a[sum].a = p.first;
        a[sum].b = p.second;    
        a[sum].cnt = tmp[x];
        sum++;
    }
    sort(a, a + sum, cmp);
    int bb[20];
    for(int i = 0; i < 16; i++) {
        cout << a[i].a << a[i].b;
        bb[i] = change(a[i].a, a[i].b);
    }
    cout << '\n';

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < s[i].size() - 1; j += 2) {
            int num = change(s[i][j], s[i][j + 1]);
            int min_tmp = INT_MAX;
            int min_index = 0;
            for(int k = 0; k < 16; k++) {
                if(min_tmp > abs(bb[k] - num)) {
                    min_tmp = abs(bb[k] - num);
                    min_index = k;
                }
            }
            cout << my_print(min_index);
        }
        cout << '\n';
    }
}
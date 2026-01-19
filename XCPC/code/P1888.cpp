#include<bits/stdc++.h>
using namespace std;
int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    cout << a/__gcd(a, c) << "/" << c/__gcd(a, c);
}
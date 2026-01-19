#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 20230610;
    int tmp = 1;
    int sum = 0;
    int pre_sum = 0;
    int step = 0;
    while(1) {
        step++;
        sum += tmp;
        pre_sum += sum;
        // cout << pre_sum << ' ' << step << '\n';
        tmp++;
        if(pre_sum >= n) break;
    }
    cout << step - 1;
}
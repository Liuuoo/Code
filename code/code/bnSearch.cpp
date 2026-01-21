#include<bits/stdc++.h>
using namespace std;
int a[123];
int n = 10; //代表数组长度
int tag = 3;

// tag或tag的前驱
int binSearch1() { 
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid] <= tag) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

// tag或tag的后继
int binSearch2() {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid] >= tag) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main() {

}
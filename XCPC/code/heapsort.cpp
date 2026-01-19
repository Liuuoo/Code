#include<bits/stdc++.h>
using namespace std;
int arr[] = {9, 6, 1, 4, 5, 2, 3, 7, 8, 10};

void iniheap() {
    for(int i = 10; i >= 1; i--) {
        int j = i;
        while(arr[j] > arr[j/2] && j > 1) {
            swap(arr[j], arr[j/2]);
            j /= 2;
        }
    }
}

void heapsort() {
    for(int i = 10; i >= 1; i--) {
        swap(arr[1], arr[i]);
        int j = 1;

        while(j < i) {

            int lc = -1, rc = -1;
            if(j * 2 <= i) lc = arr[j*2];
            if(j * 2 + 1 <= i) rc = arr[j*2 + 1];

            if(lc > rc && lc > arr[j]) {
                swap(arr[j], arr[j*2]);
                j *= 2;
            }

            if(rc > lc && rc > arr[j]) {
                swap(arr[j], arr[j*2 + 1]);
                j = j * 2 + 1;
            }
        }
    }
}

int main() {
    iniheap();
    heapsort();
    for(int i = 0; i < 10; i++) cout << arr[i] << " ";
}
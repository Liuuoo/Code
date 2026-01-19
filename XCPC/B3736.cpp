#include <iostream>
using namespace std;
int _gcd(int a, int b) {
	while(b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
} 
int main() {
	int x, y, z;
	cin >> x >> y>> z;
	cout << _gcd(_gcd(x, y), z);
}

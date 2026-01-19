#include<bits/stdc++.h>
using namespace std;

bool is_primer(int x) {
	for(int i = 2; i <= sqrt(x); i++) {
		if(x % i == 0) return false;
	}
	return true;
}

string m_to_string(int x) {
	string s;
	s = to_string(x);
	while(s.size() < 5) {
		s = "0" + s;
	}
	return s;
} 

int calc(int x, string s2) { // 当前值-目标值 
	string s1 = m_to_string(x);
	int cnt = 0;
	for(int i = 0; i < 5; i++) {
		int delt = abs(s1[i] - s2[i]);
		int tmp = min(delt, 10 - delt);
		cnt += tmp;
	}
	return cnt;
}

int main() {
	string s;
	cin >> s;
	string ans;
	int m_min = INT_MAX; 
	for(int i = 2; i <= 99999; i++) {
		if(is_primer(i)) {
			int cnt = calc(i, s); 
			if(cnt < m_min) {
				ans = m_to_string(i);
				// 需要处理前缀0 
				m_min = cnt;
			}
			else if(cnt == m_min) {
				if(stoi(ans) < i) ans = m_to_string(i);
			}
		}
	}
	cout << ans;
}

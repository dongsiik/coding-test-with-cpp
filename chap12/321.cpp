//321쪽 Q07 : 럭키 스트레이트

#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	string s;
	cin >> s;
	int half = s.size()/2;
	int left = 0;
	int right = 0;

	for (int i = 0; i < half; i++) {
		left += s[i] - '0';
	}

	for (int i = half; i < s.size(); i++) {
		right += s[i] - '0';
	}

	if (left == right) cout << "LUCKY";
	else cout << "READY";
}

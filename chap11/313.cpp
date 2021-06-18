//313쪽 Q03 : 문자열 뒤집기

#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i + 1]) cnt++;
	}
	int result = (cnt + 1) / 2;

	cout << result;
}

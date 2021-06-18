//312쪽 Q02 : 곱하기 혹은 더하기

#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	unsigned int result = s[0] - '0';
	for (int i = 1; i < s.size(); i++) {
		int num = s[i] - '0';
		if (result <= 1 || num <= 1) result += num;
		else result *= num;
	}

	cout << result << endl;

}

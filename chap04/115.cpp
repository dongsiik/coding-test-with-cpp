//115쪽 <2> : 왕실의 나이트

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int x = s[0] - 'a' + 1;
	int y = s[1] - '1' + 1;
	int result = 0;
	int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
	int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && nx < 9 && ny>0 && ny < 9) result++;
	}


	cout << result << '\n';
}
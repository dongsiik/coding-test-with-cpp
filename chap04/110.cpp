//110쪽 예제 4-1 : 상하좌우

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string route;
	int x = 1;
	int y = 1;

	cin >> n;
	cin.ignore();
	getline(cin, route);

	for (int i = 0; i < route.size(); i++) {
		if (route[i] == 'U' && y != 1) x--;
		if (route[i] == 'D' && y != n) x++;
		if (route[i] == 'L' && x != 1) y--;
		if (route[i] == 'R' && x != n) y++;
	}
	cout << x << ' ' << y;
}

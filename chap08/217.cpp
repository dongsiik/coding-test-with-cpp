//217쪽 <2> : 1로 만들기

#include <iostream>
using namespace std;

int d[30001];

int making1(int x) {
	d[0] = 0;
	d[1] = 0;
	for (int i = 2; i <= x; i++) {
		int min = 40000;
		if (i % 5 == 0 && (min > d[i / 5] + 1)) { min = d[i / 5] + 1; }
		if (i % 3 == 0 && (min > d[i / 3] + 1)) {min = d[i / 3] + 1;}
		if (i % 2 == 0 && (min > d[i / 2] + 1)) {min = d[i / 2] + 1;}
		if (min > (d[i - 1] + 1)) { min = d[i - 1] + 1;}
		d[i] = min;
	}
	return d[x];
}
int main() {
	int x;
	cin >> x;
	cout << making1(x);
}

//360쪽 Q24 : 안테나

#include <iostream>
#include <algorithm>

using namespace std;

int houses[200000];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> houses[i];
	}
	sort(houses, houses + n);
	cout << houses[(n-1) / 2];
}

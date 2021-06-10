//220쪽 <3> : 개미 전사

#include <iostream>
using namespace std;


int main() {
	int Food[100];
	int MaxFood[100];
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		Food[i] = k;
	}
	MaxFood[0] = Food[0];
	MaxFood[1] = max(Food[0], Food[1]);
	for (int i = 2; i < n; i++) {
		MaxFood[i] = max(MaxFood[i - 1], MaxFood[i - 2] + Food[i]);
	}
	cout << MaxFood[n-1];
}

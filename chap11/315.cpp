//315쪽 Q05 : 볼링공 고르기

#include <iostream>
using namespace std;

int main() {
	int arr[11] = { 0, };
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x]++;
	}

	int result = 0;
	for (int i = 1; i < n; i++) {
		n -= arr[i];
		result += n * arr[i];
	}

	cout << result << endl;
}

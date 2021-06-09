//182쪽 <4> : 두 배열의 원소 교체

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, k;
	vector<int> a, b;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		a.push_back(n);
	}
	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		b.push_back(n);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	for (int i = 0; i < k; i++) {
		a[i] = b[i];
	}
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	cout << sum;
}

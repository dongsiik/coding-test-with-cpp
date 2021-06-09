//92쪽 <2> : 큰 수의 법칙

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, k;
	vector<int> v;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	int b1 = v[n - 1];
	int b2 = v[n - 2];

	int sum = (k * b1 + b2) * (m / (k + 1)) + b1 * (m % (k + 1));
	cout << sum << endl;
}

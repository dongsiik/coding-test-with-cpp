//201쪽 <3> : 떡볶이 떡 만들기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cutting(vector<int> v, int cutter) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > cutter) sum += (v[i] - cutter);
	}
	return sum;
}
int binarySearch(vector<int> v, int target, int start, int end) {
	int M = 0;
	while (start <= end) {
		M = (start + end) / 2;
		int m = cutting(v, M);
		if (m == target) break;
		else if (m > target) start = M + 1;
		else end = M - 1;
	}
	return M;
}

int main() {
	int n, m;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int start = 0;
	int end = 1000000000;
	int height = binarySearch(v, m, start, end);
	cout << height;
}

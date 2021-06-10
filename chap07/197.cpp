//197쪽 <2> : 부품 찾기(이진 탐색)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int> arr, int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target) return true;
		else if (arr[mid] > target) end = mid - 1;
		else start = mid + 1;
	}
	return false;
}
int main() {
	int n, m;
	vector<int> nVec;
	vector<int> mVec;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nVec.push_back(x);
	}
	sort(nVec.begin(), nVec.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		mVec.push_back(x);
	}

	for (int i = 0; i < m; i++) {
		if (binarySearch(nVec, 0, n - 1, mVec[i])) cout << "yes ";
		else cout << "no ";
	}
}

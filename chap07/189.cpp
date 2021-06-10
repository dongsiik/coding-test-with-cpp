//189쪽 이진탐색(재귀함수)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int start, int end, int target) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	if (arr[mid] == target) return mid;
	else if (arr[mid] > target) return binarySearch(arr, start, mid - 1, target);
	else return binarySearch(arr, mid + 1, end, target);
}

int main() {
	int n, target;
	cin >> n >> target;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int idx;
	idx = binarySearch(v, 0, n - 1, target);
	if (idx == -1) cout << "찾는 값이 없습니다.";
	else cout << "인덱스는 " << idx;
}

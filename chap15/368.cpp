//368쪽 Q28 : 고정점 찾기

#include <iostream>

using namespace std;

int arr[1000000];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = n;
	int fp = -1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] < mid) start = mid + 1;
		if (arr[mid] > mid) end = mid - 1;
		if (arr[mid] == mid) {
			cout << "s, e, m, arr[m] " << start << ' ' << end << ' ' << mid << ' ' << arr[mid] << endl;
			fp = mid;
			break;
		}
	}
	cout << fp;
}

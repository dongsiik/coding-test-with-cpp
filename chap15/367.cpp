//367쪽 Q27 : 정렬된 배열에서 특정 수의 개수 구하기

#include <iostream>

using namespace std;

int arr[1000000];
int n, x;

int main() {
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start=0;
	int end=n;
	int leftmost = -1;
	int rightmost = -1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] < x) start = mid + 1;
		if (arr[mid] > x) end = mid - 1;
		if (arr[mid] == x && mid < n-1) {
			if (arr[mid + 1] != x) {
				rightmost = mid;
				break;
			}
			else start = mid + 1;
		}
	}

	start = 0;
	end = n;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] < x) start = mid + 1;
		if (arr[mid] > x) end = mid - 1;
		if (arr[mid] == x && mid >0) {
			if (arr[mid - 1] != x) {
				leftmost = mid;
				break;
			}
			else end = mid - 1;
		}
	}

	if (leftmost == -1 && rightmost == -1) cout << "-1";
	else cout << (rightmost - leftmost) + 1;


}

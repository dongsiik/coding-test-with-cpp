//369쪽 Q29 : 공유기 설치

#include <algorithm>
#include <iostream>

using namespace std;

int arr[200000];
int n, c;

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int start = 1;
	int end = arr[n - 1] - arr[0];
	int answer = 0;

	while (start <= end) {
		int step = (start + end) / 2;
		int value = arr[0];
		int cnt = 1;

		for (int i = 1; i < n; i++) {
			if (arr[i] >= value + step) {
				value = arr[i];
				cnt++;
			}
		}

		if (cnt >= c) {
			start = step + 1;
			answer = step;
		}
		else {
			end = step - 1;
		}
	}

	cout << answer;
}

//331쪽 Q01 : 모험가 길드

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int count = 0;
	int arr[100000];

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}
	sort(arr, arr + n);
	int idx = 0;
	while (idx<n) {
		int lastIdx = idx + arr[idx] - 1;
		while (arr[lastIdx] > lastIdx - idx + 1) lastIdx++;
		if (lastIdx >= n )break;
		else {
			count++;
			idx = lastIdx + 1;
		}
	}

	cout << count << endl;
}

//178쪽 <2> : 위에서 아래로

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int* arr;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}
	sort(arr, arr + n,greater<int>());
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	
	delete[] arr;
}

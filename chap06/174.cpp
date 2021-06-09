//174쪽 계수 정렬

#include <iostream>
using namespace std;

int main() {
	int n = 15;
	int arr[15] = { 7,5,9,0,3,1,6,2,9,1,4,8,0,5,2 };
	int cnt[10] = { 0, };

	for (int i = 0; i < n; i++) {
		cnt[arr[i]]++;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << ' ';
		}
	}
}

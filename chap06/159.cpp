//159쪽 선택 정렬

#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int array[10] = { 7,5,9,0,3,1,6,2,4,8 };

	for (int i = 0; i < 10; i++) {
		int min_idx = i;
		for (int j = i + 1; j < 10; j++) {
			if (array[j] < array[min_idx]) min_idx = j;
		}
		swap(array[i], array[min_idx]);
	}

	for (int i = 0; i < 10; i++) cout << array[i]<<' ';
}

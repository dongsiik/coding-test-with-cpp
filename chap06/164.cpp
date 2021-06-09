//164쪽 삽입 정렬

#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int array[10] = { 7,5,9,0,3,1,6,2,4,8 };

	for (int i = 1; i < 10; i++) {
		for (int j = i; j > 0; j--) {
			if (array[j] < array[j - 1]) swap(array[j], array[j - 1]);
			else break;
		}
	}

	for (int i = 0; i < 10; i++) cout << array[i]<<' ';
}

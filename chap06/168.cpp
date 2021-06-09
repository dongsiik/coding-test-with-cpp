//168쪽 퀵 정렬

#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(int* arr, int start, int end) {
	if (start >= end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right) {
		while (left <= end && arr[left] <= arr[pivot]) left++;
		while (right >= start + 1 && arr[right] >= arr[pivot]) right--;
		if (left > right) swap(arr[pivot], arr[right]);
		else swap(arr[left], arr[right]);
	}
	QuickSort(arr, start, right - 1);
	QuickSort(arr, right + 1, end);


}
int main() {
	int array[10] = { 5,7,9,0,3,1,6,2,4,8 };

	QuickSort(array, 0, 9);

	for(int i = 0; i < 10; i++) cout << array[i]<<' ';
}

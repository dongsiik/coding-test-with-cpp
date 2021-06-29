//363쪽 Q26 : 카드 정렬하기

#include <iostream>
#include <queue>

using namespace std;



int main() {
	priority_queue<int> q;
	int n;
	int result = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(-x);
	}

	while (q.size() != 1) {
		int one = -q.top();
		q.pop();
		int two = -q.top();
		q.pop();
		int sum = one + two;
		result += sum;
		q.push(-sum);
	}

	cout << result;

}

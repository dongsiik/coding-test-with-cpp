//87�� ���� 3-1 : �Ž����� ����

#include <iostream>
using namespace std;

int main() {
	int n;
	int count = 0;
	int coins[4] = { 500,100,50,10 };

	cin >> n;
	for (int i = 0; i < 4; i++) {
		count += n / coins[i];
		n %= coins[i];
	}
	cout << count;
}
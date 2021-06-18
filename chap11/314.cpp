//314쪽 Q04 : 만들 수 없는 금액

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> coins;
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		coins.push_back(x);
	}
	sort(coins.begin(), coins.end());

	int target = 1;
	for (int i = 0; i < n; i++) {
		if (target < coins[i]) break;
		target += coins[i];
	}

	cout << target << '\n';
}

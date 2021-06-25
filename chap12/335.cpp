//332쪽 Q13 : 치킨 배달
//책의 코드를 그대로 베겼습니다. 다시 풀 때 독창적인 코드로 바꾸겠습니다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getSum(vector<pair<int, int>> mChicken, vector<pair<int, int>> house) {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int tmp = 1e9;
		int hx = house[i].first;
		int hy = house[i].second;
		for (int j = 0; j < mChicken.size(); j++) {
			int mx = mChicken[j].first;
			int my = mChicken[j].second;
			int mLength = abs(hx - mx) + abs(hy - my);
			tmp = min(tmp, mLength);
		}
		sum += tmp;
	}
	return sum;
}

int main() {
	int arr[51][51];
	int n, m;
	vector<pair<int, int>> house;
	vector<pair<int, int>> chicken;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back({ i,j });
			if (arr[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	vector<bool> permuHelper;
	for (int i = 0; i < (chicken.size() - m); i++) {
		permuHelper.push_back(false);
	}
	for (int i = 0; i < m; i++) {
		permuHelper.push_back(true);
	}
	
	int result = 1e9;

	do {
		vector<pair<int, int>> mChicken;
		for (int i = 0; i < chicken.size(); i++) {
			if (permuHelper[i] == true) {
				int mx = chicken[i].first;
				int my = chicken[i].second;
				mChicken.push_back({ mx,my });
			}
		}
		result = min(result, getSum(mChicken, house));
	} while (next_permutation(permuHelper.begin(), permuHelper.end()));

	cout << result;
}

//180쪽 <3> : 성적이 낮은 순서로 학생 출력하기

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second < b.second) return true;
	else return false;
}

int main() {
	int n;
	vector<pair<string, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int t;
		cin >> s >> t;
		v.push_back({ s,t });
		cout << v[i].first << endl;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) cout << v[i].first << ' ';
}

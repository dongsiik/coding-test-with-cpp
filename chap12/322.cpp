//322쪽 Q08 : 문자열 재정렬

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<char> v;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (isalpha(s[i])) v.push_back(s[i]);
		else sum += s[i] - '0';
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << sum;
}

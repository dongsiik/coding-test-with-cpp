//359쪽 Q23 : 국영수
//백준 온라인 저지에서 결과값을 출력할 때 endl을 사용하면 시간 초과가 뜹니다. '\n'을 사용합시다.
//듣기로는 cin, cout대신 scanf, printf를 사용하면 좀 더 빠르다고 합니다.
//아니면 코드 처음에 ios::sync_with_stdio(false); 를 써보세요.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class student {
public:
	string name;
	int kor;
	int eng;
	int math;
	student(string n, int k, int e, int m) {
		name = n; kor = k; eng = e; math = m;
	}
	bool operator <(student& op2) {
		if (this->kor == op2.kor && this->eng == op2.eng && this->math == op2.math) {
			return this->name < op2.name;
		}
		if (this->kor == op2.kor && this->eng == op2.eng) {
			return this->math > op2.math;
		}
		if (this->kor == op2.kor) {
			return this->eng < op2.eng;
		}
		return this->kor > op2.kor;
	}
};

vector<student> ban;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int kor;
		int eng;
		int math;
		cin >> name >> kor >> eng >> math;
		ban.push_back(student(name, kor, eng, math));
	}

	sort(ban.begin(), ban.end());

	for (int i = 0; i < n; i++) {
		cout << ban[i].name << endl;
	}
}

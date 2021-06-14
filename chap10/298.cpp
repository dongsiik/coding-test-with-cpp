//298쪽 <2> : 팀 결성

#include <iostream>
using namespace std;

int n, m;
int parent[100001];

int findParent(int x) {
	if(x == parent[x]) return x;
	else {
		parent[x] = findParent(parent[x]);
		return parent[x];
	}
}

void ope0(int a, int b) {
	a = parent[a];
	b = parent[b];
	if (a > b) parent[a] = parent[b];
	else parent[b] = parent[a];
}

void ope1(int a, int b) {
	if (parent[a] == parent[b]) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int ope, a, b;
		cin >> ope >> a >> b;
		if (ope == 0) ope0(a, b);
		else ope1(a, b);
	}
}

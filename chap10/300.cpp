//300쪽 <3> : 도시 분할 계획

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[100001];
vector<pair<int, pair<int, int>>> graph;

int findParent(int x) {
	if (x == parent[x]) return x;
	else {
		parent[x] = findParent(parent[x]);
		return parent[x];
	}
}

bool unionParent(int a, int b) {
	a = parent[a];
	b = parent[b];
	if (a == b) return false;
	else if (a > b) parent[a] = parent[b];
	else parent[b] = parent[a];
}

int plan() {
	sort(graph.begin(), graph.end());
	int sum = 0;
	int count = 0;
	int i = 0;

	while(count<(n-2)){

		int c = graph[i].first;
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		if (unionParent(a, b)) {
			count++;
			sum += c;
		}
		i++;
	}

	return sum;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c,{a,b} });
	}

	int cost = plan();
	cout << cost << endl;
}

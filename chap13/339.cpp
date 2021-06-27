//339쪽 Q15 : 특정 거리의 도시 찾기

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[300001];
int d[300001];

int main() {
	int n, m, k, x;
	fill(d, d + 300001, -1);

	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	queue<int> q;
	d[x] = 0;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			if (d[graph[now][i]] == -1) {
				d[graph[now][i]] = d[now] + 1;
				q.push(graph[now][i]);
			}
		}
	}

	bool chk = false;

	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			cout << i << endl;
			chk = true;
		}
	}

	if (chk == false) cout << -1 << endl;
}

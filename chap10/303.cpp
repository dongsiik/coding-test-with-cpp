//303쪽 <4> : 커리큘럼

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> graph[501];
int t[501];
int result[501];
int sunsoo[501];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		t[i] = a;
		result[i] = a;
		cin >> a;
		while (a != -1) {
			sunsoo[i]++;
			graph[a].push_back(i);
			cin >> a;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (sunsoo[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + t[graph[now][i]]);
			sunsoo[graph[now][i]]--;
			if (sunsoo[graph[now][i]] == 0) {
				q.push(graph[now][i]);
			}
		}
		cout << now << "번 과목 완료\n";
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << endl;
	}
}

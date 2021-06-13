//262쪽 <3> : 전보

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int n, m, c;
vector<pair<int, int>> graph[30001];
int d[30001];

void dijkstra(int start) {
	priority_queue<pair<int,int>> pq;
	d[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = - pq.top().first;
		pq.pop();

		if (d[now] < dist) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main() {
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back(make_pair(y, z));
	}
	fill(d, d + 30001, INF);

	dijkstra(c);

	int count = -1;
	int maxT = 0;

	for (int i = 1; i <= n; i++) {
		if (d[i] < INF) {
			count++;
			maxT = max(maxT, d[i]);
		}
	}

	cout << count << ' ' << maxT << endl;
}

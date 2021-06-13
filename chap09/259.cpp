//259쪽 <2> : 미래 도시

#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m;
int graph[101][101];

int main() {
	cin >> n >> m;
	for (int i = 1; i <101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int x, k;
	cin >> x >> k;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	int distance = graph[1][k] + graph[k][x];
	if (distance >= INF) cout << "-1" << endl;
	else cout << distance<<endl;
}

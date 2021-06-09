//147쪽 BFS 예제

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool visited[9] = { false,false,false,false,false,false,false,false,false };
vector<int> graph[9];

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (visited[y] == false) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    BFS(1);
}

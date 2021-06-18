//316쪽 Q06 : 무지의 먹방 라이브

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    long long totalTime = 0;
    for (int i = 0; i < food_times.size(); i++) {
        totalTime += food_times[i];
    }
    if (totalTime <= k) return -1;
    
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({ -food_times[i],i + 1 });
    }

    totalTime = 0;
    int menuNum = food_times.size();
    long long currentTime = 0;

    while (totalTime + ((-pq.top().first - currentTime)) * menuNum <= k) {
        int now = -pq.top().first;
        pq.pop();
        totalTime += (now - currentTime) * menuNum;
        currentTime = now;
        menuNum-=1;
    }

    vector<pair<int, int>> result;
    while (!pq.empty()) {
        int f_time = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        result.push_back({ f_time,idx });
    }
    sort(result.begin(), result.end(), compare);
    return result[(k - totalTime) % menuNum].second;
}

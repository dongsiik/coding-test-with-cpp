//335쪽 Q14 : 외벽 점검
//책의 코드를 그대로 베꼈습니다. 다시 풀면서 독창적인 코드로 바꾸겠습니다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end());
    int answer = dist.size() + 1;

    int length = weak.size();
    for (int i = 0; i < length; i++) {
        weak.push_back(weak[i] + n);
    }

    for (int start = 0; start < length; start++) {
        do {
            int cnt = 1;
            int position = weak[start] + dist[0];
            for (int idx = start; idx < start + length; idx++) {
                if (position < weak[idx]) {
                    cnt++;
                    if (cnt > dist.size()) break;
                    position = weak[idx] + dist[cnt - 1];
                }
                
            }
            answer = min(answer, cnt);
        } while (next_permutation(dist.begin(), dist.end()));
    }


    if (answer > dist.size()) return -1;

    return answer;
}

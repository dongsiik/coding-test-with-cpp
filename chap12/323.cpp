//323쪽 Q09 : 문자열 압축

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int unit = 1; unit <= s.size() / 2; unit++) {
        string compressed = "";
        string pattern = s.substr(0, unit);
        int count = 1;
        for (int i = unit; i < s.size(); i += unit) {
            string now = s.substr(i, unit);
            if (pattern == now) count++;
            else {
                compressed += (count > 1) ? to_string(count) + pattern : pattern;
                pattern = now;
                count = 1;
            }
        }
        compressed += (count > 1) ? to_string(count) + pattern : pattern;
        answer = min(answer, (int)compressed.length());
    }
    return answer;
}

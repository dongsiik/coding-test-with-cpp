//370쪽 Q30 : 가사 검색

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string replaceQmark(string s, char c) {
    string result = s;
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == '?') result[i] = c;
    }
    return result;
}

int count(vector<string>& v, string q) {
    auto rightmost = upper_bound(v.begin(), v.end(), replaceQmark(q,'z')) - v.begin();
    auto leftmost = lower_bound(v.begin(), v.end(), replaceQmark(q, 'a')) - v.begin();

    return rightmost - leftmost;
}

vector<string> arr[100001];
vector<string> rarr[100001];

vector<int> solution(vector<string> words, vector<string> queries) {
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        int length = words[i].size();
        arr[length].push_back(word);
        reverse(word.begin(), word.end());
        rarr[length].push_back(word);
    }

    for (int i = 0; i <= 100000; i++) {
        sort(arr[i].begin(), arr[i].end());
        sort(rarr[i].begin(), rarr[i].end());
    }

    vector<int> answer;
    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        int length = query.size();
        int cnt = 0;
        if (query[0] == '?') {
            reverse(query.begin(), query.end());
            cnt = count(rarr[length], query);
        }
        else {
            cnt = count(arr[length], query);
        }
        answer.push_back(cnt);
        
    }
    return answer;
}

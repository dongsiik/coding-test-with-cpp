//346쪽 Q18 : 괄호 변환

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gyun(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') result += 1;
        if (s[i] == ')') result -= 1;
        if (result == 0) return i+1;
    }
}

bool rightString(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') result++;
        if (s[i] == ')') result--;
        if (result < 0) return false;
    }
    return true;
}

string cutU(string u) {
    string answer = "";
    for (int i = 1; i < u.size() - 1; i++) {
        if (u[i] == '(') answer += ')';
        if (u[i] == ')') answer += '(';
    }
    return answer;
}

string solution(string p) {
    if (p == "" || rightString(p) == true) return p;
    int i = gyun(p);
    string u = p.substr(0, i);
    string v = p.substr(i, p.size() - i);
    if (rightString(u)) {
        cout << "case 3:\n"; return u + solution(v);
    }
    else {
        cout << "case 4:\n";
        return "(" + solution(v) + ")" + cutU(u);
    }
}

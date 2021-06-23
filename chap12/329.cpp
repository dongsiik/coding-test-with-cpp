//329쪽 Q12 : 기둥과 보 설치
//이 코드는 많은 테스트 케이스를 통과하지 못하는 불완전한 코드입니다. 조만간 고치겠습니다.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool G[101][101];
bool B[101][101];

bool insertG(int x, int y, int n) {
    if (y == 0) return true;
    if (y > 0) {
        if ((G[x][y - 1] == true)) return true;
    }
    if (x > 0) {
        if ((B[x - 1][y] == true)) return true;
    }
    if (x < n) {
        if ((B[x][y] == true)) return true;
    }
    return false;
}

bool insertB(int x, int y, int n) {
    if (y > 0) {
        if (G[x][y - 1] == true) return true;
    }
    if (y > 0 && x < n){
        if (G[x + 1][y - 1] == true) return true;
    }
    if (x > 0 && x < n - 1) {
        if ((B[x - 1][y] == true) && (B[x + 1][y] == true)) return true;
    }
    return false;
}

bool deleteG(int x, int y, int n) {
    if (G[x][y] == false) return false;
    G[x][y] = false;
    if (y < n - 1){
        if ((G[x][y + 1] == true) && (insertG(x, y + 1, n) == false)) {
            G[x][y] == true; return false;
        }
    }
    if (x > 0 && y < n){
        if((B[x - 1][y + 1] == true) && (insertB(x - 1, y + 1, n) == false) ){
            G[x][y] == true; return false;
        }
    }
    if (x < n && y < n ) {
        if (insertB(x, y + 1, n) == false && (B[x][y + 1] == true)) {
            G[x][y] == true; return false;
        }
    }
    G[x][y] = true;
    return true;
}

bool deleteB(int x, int y, int n) {
    if (B[x][y] == false) return false;
    B[x][y] = false;

    if (y < n && (G[x][y]) == true) {
        cout << "철거중 : 이 위에 기둥 있음!" << endl;
        if (insertG(x, y, n) == false) {
            B[x][y] = true; return false;
        }
    }
    if (y < n && x<n&& (G[x+1][y]) == true) {
        cout << "철거중 : 오른쪽위에 기둥 있음!" << endl;
        if (insertG(x+1, y, n) == false) {
            cout << "오른쪽위에 기둥 무너짐" << endl; B[x][y] = true; return false;
        }
    }
    if (x >0 && (B[x-1][y]) == true) {
        cout << "철거중 : 왼쪽에 보 있음!" << endl;

        if (insertB(x-1, y, n) == false) {
            cout << "왼쪽 보 무너짐" << endl; B[x][y] = true; return false;
        }
    }
    if (x < n-1 && (B[x+1][y]) == true) {
        cout << "철거중 : 오른쪽에 보 있음!" << endl;

        if (insertB(x+1, y, n) == false) {
            cout << "오른쪽 보 무너짐" << endl; B[x][y] = true; return false;
        }
    }

    B[x][y] = true;
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            B[i][j] == false;
            G[i][j] == false;
        }
    }

    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        cout << "i :" << i<<endl;
        if (a == 0 && b == 0) {
            if (deleteG(x, y, n)) G[x][y] = false;
        }
        if (a == 0 && b == 1) {
            if (insertG(x, y, n)) G[x][y] = true;
        }
        if (a == 1 && b == 0) {
            if (deleteB(x, y, n)) B[x][y] = false;
        }
        if (a == 1 && b == 1) {
            if (insertB(x, y, n)) B[x][y] = true;
        }
    }

    vector<vector<int>> answer;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (G[x][y] == true) {
                vector<int> tmpG;
                tmpG.push_back(x);
                tmpG.push_back(y);
                tmpG.push_back(0);
                answer.push_back(tmpG);
            }
            if (B[x][y] == true) {
                vector<int> tmpB;
                tmpB.push_back(x);
                tmpB.push_back(y);
                tmpB.push_back(1);
                answer.push_back(tmpB);
            }
        }
    }
    return answer;
}

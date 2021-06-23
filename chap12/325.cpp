//325 Q10 : 자물쇠와 열쇠

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//90도 회전하는 함수
vector<vector<int>> rotate(vector<vector<int>> key) {
    int n = key.size();
    vector<vector<int>> rot = key;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rot[j][n - i - 1] = key[i][j];
        }
    }
    return rot;
}

//열쇠와 자물쇠가 맞는지 확인하는 함수
bool check(vector<vector<int>> bigLock) {
    int n = bigLock.size()/3;
    for (int i = n; i < 2*n; i++) {
        for (int j = n; j < 2*n; j++) {
            if (bigLock[i][j] != 1) return false;
        }
    }
    return true;
}

//특정 위치로 열쇠를 넣고 맞는지까지 확인하는 함수
bool matching(vector<vector<int>> key, vector<vector<int>> lock, int x, int y) {
    int n = lock.size();
    vector<vector<int>> bigLock(n * 3, vector<int>(n * 3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bigLock[i + n][j + n] = lock[i][j];
        }
    }
    int m = key.size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            bigLock[i + x][j + y] += key[i][j];
        }
    }
    bool result = check(bigLock);
    return result;
}

//여러 방향과 위치로 자물쇠와 열쇠를 시험해보는 함수
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();

    for (int r = 0; r < 4; r++) {
        key = rotate(key);
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                if (matching(key, lock, i, j) == true) return true;
            }
        }
    }
    return false;
}

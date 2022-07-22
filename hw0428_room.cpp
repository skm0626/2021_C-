#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct element { char x, y; };
element direc[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

char room[100][100];
char visited[100][100];

int m, n;
int cnt;
void roomCount(int x, int y) {
    visited[x][y] = '+';
    cnt++;
    for (int i = 0; i < 4; i++) {
        int next_Y = y + direc[i].y;
        int next_X = x + direc[i].x;
        if (0 <= next_Y && next_Y < m && 0 <= next_X && next_X < n) {
            if (room[next_X][next_Y] == '.' && visited[next_X][next_Y] != '+')
                roomCount(next_X, next_Y);
        }
    }
}
int main() {
    string s;
    cin >> m >> n;

    fill(&room[0][0], &room[n - 1][m], 0);
    fill(&visited[0][0], &visited[n - 1][m], 0);

    for (int j = 0; j < n; j++) {
        cin >> s;
        for (int k = 0; k < m; k++) {
            room[j][k] = s[k];
        }
    }
    vector<int>room_cnt;

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            if (room[j][k] == '.' && visited[j][k] != '+') {
                cnt = 0;
                roomCount(j, k);
                room_cnt.push_back(cnt);
            }
        }
    }
    cout << room_cnt.size() << endl;
    sort(room_cnt.begin(), room_cnt.end(), greater<int>());
    for (int c = 0; c < room_cnt.size(); c++) cout << room_cnt[c] << " ";
    cout << endl;
    return 0;
}

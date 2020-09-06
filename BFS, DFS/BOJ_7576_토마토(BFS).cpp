#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(int argc, const char * argv[]) {
    const int MAX = 1000;
    int m, n; // 상자의 가로, 세로
    int box[MAX][MAX];
    bool visited[MAX][MAX];
    int x_direction[] = { 0, 1, 0, -1 };
    int y_direction[] = { -1, 0, 1, 0 };
    queue<pair<int, int>> q;
    int cnt_to_check = 0; //하루에 체크해야 할 토마토 개수
    int day = 0;
    
    cin >> m >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int input;
            
            cin >> input;
            box[i][j] = input;
            
            if (input == 1) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
                ++cnt_to_check;
            }
        }
    }

    while (!q.empty()) {
        int cnt = 0;
        bool ripen = false;
        
        for (int i = 0; i < cnt_to_check; i++) {
            pair<int, int> node = q.front();
            q.pop();
            
            for (int j = 0; j < 4; j++) {
                int next_y = node.first + y_direction[j];
                int next_x = node.second + x_direction[j];
                
                if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m
                        && box[next_y][next_x] == 0 && !visited[next_y][next_x]) {
                    box[next_y][next_x] = 1;
                    q.push(make_pair(next_y, next_x));
                    visited[next_y][next_x] = true;
                    ++cnt;
                    ripen = true;
                }
            }
        }
        
        cnt_to_check = cnt;
        if (ripen) ++day;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    
    cout << day << '\n';
    
    return 0;
}

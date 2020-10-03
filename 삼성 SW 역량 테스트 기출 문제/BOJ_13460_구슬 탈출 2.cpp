#include <iostream>
#include <queue>

using namespace std;

char board[10][10];
bool visited[10][10][10][10];
int y_dir[4] = {-1, 0, 1, 0};
int x_dir[4] = {0, 1, 0, -1};

struct position{
    int y_red, x_red, y_blue, x_blue;
    int move_cnt;
};

void move(int& y, int& x, int dir) {
    while (true) {
        y += y_dir[dir]; x += x_dir[dir];
        if (board[y][x] == '#') {
            y -= y_dir[dir]; x -= x_dir[dir];
            break;
        }
        else if (board[y][x] == 'O')
            break;
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    
    int y_des, x_des, y_red, x_red, y_blue, x_blue;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char input;
            cin >> input;
            board[i][j] = input;
            if (input == 'R') {
                y_red = i; x_red = j;
            }
            else if (input == 'B') {
                y_blue = i; x_blue = j;
            }
            else if (input == 'O') {
                y_des = i; x_des = j;
            }
        }
    }
    
    int ans = -1;
    queue<position> q;
    q.push({y_red, x_red, y_blue, x_blue, 0});
    visited[y_red][x_red][y_blue][x_blue] = true;
    
    while (!q.empty()) {
        position pos = q.front();
        q.pop();
        
        if (pos.move_cnt > 10) break;
        
        if (pos.y_red == y_des && pos.x_red == x_des) {
            ans = pos.move_cnt;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int y_red = pos.y_red, x_red = pos.x_red;
            int y_blue = pos.y_blue, x_blue = pos.x_blue;
            
            move(y_red, x_red, i);
            move(y_blue, x_blue, i);
            
            if (y_blue == y_des && x_blue == x_des) continue;
            
            if (y_red == y_blue && x_red == x_blue) {
                switch (i) {
                    case 0: // up
                        pos.y_red > pos.y_blue ? y_red++ : y_blue++;
                        break;
                    case 1: // right
                        pos.x_red > pos.x_blue ? x_blue-- : x_red--;
                        break;
                    case 2: // down
                        pos.y_red > pos.y_blue ? y_blue-- : y_red--;
                        break;
                    case 3: // left
                        pos.x_red > pos.x_blue ? x_red++ : x_blue++;
                        break;
                }
            }
            
            if (!visited[y_red][x_red][y_blue][x_blue]) {
                q.push({y_red, x_red, y_blue, x_blue, pos.move_cnt + 1});
                visited[y_red][x_red][y_blue][x_blue] = true;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}

#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 1000;
int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX][2]; // 세 번째 인덱스에 벽을 부쉈는지 여부 체크
int x_direction[] = { 0, 1, 0, -1 };
int y_direction[] = { -1, 0, 1, 0 };

struct move_info {
    int y, x;
    int broke_count, move_count;
};

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            board[i][j] = input[j] - '0';
        }
    }
    
    queue<move_info> q;
    q.push({0, 0, 0, 1}); // y, x, broke_count, move_count
    visited[0][0][0] = true;
    
    while(!q.empty()) {
        move_info node = q.front();
        q.pop();
        
        if (node.y == n - 1 && node.x == m - 1) {
            cout << node.move_count << '\n';
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int next_x = node.x + x_direction[i];
            int next_y = node.y + y_direction[i];
            
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n) {
                if (board[next_y][next_x] == 0 && !visited[next_y][next_x][node.broke_count]) {
                    q.push({ next_y, next_x, node.broke_count, node.move_count + 1});
                    visited[next_y][next_x][node.broke_count] = true;
                }
                
                if (node.broke_count == 0 && board[next_y][next_x] == 1 && !visited[next_y][next_x][1]) {
                    q.push({ next_y, next_x, 1, node.move_count + 1 });
                    visited[next_y][next_x][1] = true;
                }
            }
        }
    }
    
    cout << "-1\n";
    return 0;
}

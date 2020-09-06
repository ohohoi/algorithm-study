#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200;
const int MAX_K = 30;
int k, w, h; //가능한 말 동작 횟수, 격자판 가로 길이, 세로 길이
bool board[MAX][MAX];
bool visited[MAX][MAX][MAX_K];
int horse_x[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int horse_y[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int monkey_x[4] = { 0, 1, 0, -1 };
int monkey_y[4] = { -1, 0, 1, 0 };

struct node {
    int x;
    int y;
    int move_count;
    int horse_move_count;
};

int bfs();

int main(int argc, const char * argv[]) {
    cin >> k >> w >> h;
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> board[y][x];
        }
    }
    
    int min_count = bfs();
    cout << min_count << '\n';
    
    return 0;
}

int bfs() {
    queue<node> q;
    node start_node;
    start_node.x = 0;
    start_node.y = 0;
    start_node.move_count = 0;
    start_node.horse_move_count = 0;
    q.push(start_node);
    visited[0][0][0] = true;
    
    while(!q.empty()) {
        node curr_node = q.front();
        q.pop();
        
        if (curr_node.x == w - 1 && curr_node.y == h - 1) return curr_node.move_count;
        
        if (curr_node.horse_move_count < k) {
            for (int i = 0; i < 8; i++) {
                int next_x = curr_node.x + horse_x[i];
                int next_y = curr_node.y + horse_y[i];
                
                if (next_x >= 0 && next_x < w && next_y >= 0 && next_y < h) {
                    if (board[next_y][next_x] == 0 && !visited[next_y][next_x][curr_node.horse_move_count + 1]) {
                        node next_node;
                        next_node.x = next_x;
                        next_node.y = next_y;
                        next_node.move_count = curr_node.move_count + 1;
                        next_node.horse_move_count = curr_node.horse_move_count + 1;
                        q.push(next_node);
                        visited[next_y][next_x][next_node.horse_move_count] = true;
                    }
                }
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int next_x = curr_node.x + monkey_x[i];
            int next_y = curr_node.y + monkey_y[i];
            
            if (next_x >= 0 && next_x < w && next_y >= 0 && next_y < h) {
                if (board[next_y][next_x] == 0 && !visited[next_y][next_x][curr_node.horse_move_count]) {
                    node next_node;
                    next_node.x = next_x;
                    next_node.y = next_y;
                    next_node.move_count = curr_node.move_count + 1;
                    next_node.horse_move_count = curr_node.horse_move_count;
                    q.push(next_node);
                    visited[next_y][next_x][next_node.horse_move_count] = true;
                }
            }
        }
    }
    
    return -1;
}

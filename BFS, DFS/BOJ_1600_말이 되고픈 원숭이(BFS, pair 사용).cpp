#include <iostream>
#include <queue>
#include <utility>

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
    queue< pair< pair<int, int>, pair<int, int> > > q; // pair<y, x> and pair<move_count, horse_move_count>
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    visited[0][0][0] = true;
    
    while(!q.empty()) {
        pair< pair<int, int>, pair<int, int>> node = q.front();
        q.pop();
        
        if (node.first.first == h - 1 && node.first.second == w - 1) return node.second.first;
        
        if (node.second.second < k) {
            for (int i = 0; i < 8; i++) {
                int next_y = node.first.first + horse_y[i];
                int next_x = node.first.second + horse_x[i];
                
                if (next_y >= 0 && next_y < h && next_x >= 0 && next_x < w) {
                    if (board[next_y][next_x] == 0 && !visited[next_y][next_x][node.second.second + 1]) {
                        q.push(make_pair(make_pair(next_y, next_x), make_pair(node.second.first + 1, node.second.second + 1)));
                        visited[next_y][next_x][node.second.second + 1] = true;
                    }
                }
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int next_y = node.first.first + monkey_y[i];
            int next_x = node.first.second + monkey_x[i];
            
            if (next_y >= 0 && next_y < h && next_x >= 0 && next_x < w) {
                if (board[next_y][next_x] == 0 && !visited[next_y][next_x][node.second.second]) {
                    q.push(make_pair(make_pair(next_y, next_x), make_pair(node.second.first + 1, node.second.second)));
                    visited[next_y][next_x][node.second.second] = true;
                }
            }
        }
    }
    
    return -1;
}

#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

const char W = 'W';
const char B = 'B';

int dir_r[] = {-1, 0, 1, 0}; // up, right, down, left
int dir_c[] = {0, 1, 0, -1};

int main() {
    int r, c;
    
    cin >> c >> r;
    
    char war_board[r][c];
    
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            cin >> war_board[ri][ci];
        }
    }
    
    int cnt_w = 0, cnt_b = 0;
    bool is_visited[r][c];
    
    memset(is_visited, false, sizeof(is_visited));
    
    for (int sr = 0; sr < r; sr++) {
        for (int sc = 0; sc < c; sc++) {
            if (is_visited[sr][sc]) continue;
            
            char team = war_board[sr][sc];
            int cnt = 0;
            
            queue<pair<int, int>> q; // pair first: r, second: c
            
            q.push(make_pair(sr, sc));
            is_visited[sr][sc] = true;
            
            while (!q.empty()) {
                int cr = q.front().first, cc = q.front().second;
                
                q.pop();
                cnt++;
                
                for (int di = 0; di < 4; di++) {
                    int nr = cr + dir_r[di], nc = cc + dir_c[di];
                    
                    if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
                    if (is_visited[nr][nc]) continue;
                    if (war_board[nr][nc] != team) continue;
                    
                    q.push(make_pair(nr, nc));
                    is_visited[nr][nc] = true;
                }
            }
            
            if (team == W) cnt_w += cnt * cnt;
            else if (team == B) cnt_b += cnt * cnt;
        }
    }
    
    cout << cnt_w << ' ' << cnt_b << '\n';
    
    return 0;
}

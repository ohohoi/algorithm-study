#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

const int CNT_DIR = 8;

int dir_r[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dir_c[] = {1, 2, 2, 1, -1, -2, -2, -1};

struct horse {
    int r;
    int c;
    int cnt_move = 0;
};

int main() {
    int test_case;
    
    cin >> test_case;
    
    while(test_case--) {
        int n;
        
        cin >> n;
        
        bool is_visited[n][n];
        
        memset(is_visited, false, sizeof(is_visited));
        
        int sr, sc, er, ec;
        
        cin >> sr >> sc >> er >> ec;
        
        queue<horse> q;
        
        q.push({sr, sc});
        is_visited[sr][sc] = true;
        
        while (!q.empty()) {
            int cr = q.front().r, cc = q.front().c, cnt = q.front().cnt_move;
            
            q.pop();
            
            if (cr == er && cc == ec) {
                cout << cnt << '\n';
                
                break;
            }
            
            for (int di = 0; di < CNT_DIR; di++) {
                int nr = cr + dir_r[di], nc = cc + dir_c[di];
                
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (is_visited[nr][nc]) continue;
                
                q.push({nr, nc, cnt + 1});
                is_visited[nr][nc] = true;
            }
        }
    }
    
    return 0;
}

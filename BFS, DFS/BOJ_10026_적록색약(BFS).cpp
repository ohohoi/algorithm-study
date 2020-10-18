#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

const int MAX = 100;
int n;
bool visited[MAX][MAX];
int r_dir[4] = {-1, 0, 1, 0};
int c_dir[4] = {0, 1, 0, -1};

void bfs(int r, int c, char picture[MAX][MAX]) {
    char color = picture[r][c];
    queue<pair<int, int>> q;
    
    q.push(pair<int, int>(r, c));
    visited[r][c] = true;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = curr.first + r_dir[i], nc = curr.second + c_dir[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc] && picture[nr][nc] == color) {
                q.push(pair<int, int>(nr, nc));
                visited[nr][nc] = true;
            }
        }
    }
}

int main() {
    cin >> n;
    
    char picture[MAX][MAX];
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            picture[i][j] = input[j];
        }
    }
    
    int cnt = 0, cnt_rg = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                cnt++;
                bfs(i, j, picture);
            }
            if (picture[i][j] == 'R') picture[i][j] = 'G';
        }
    }
    
    memset(visited, false, sizeof(visited));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                cnt_rg++;
                bfs(i, j, picture);
            }
        }
    }
    
    printf("%d %d\n", cnt, cnt_rg);
    return 0;
}

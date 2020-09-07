#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 50;
int n, m, k; // height, width, num of cabbages
bool cabbage_exist[MAX][MAX];
bool visited[MAX][MAX];
int x_direction[] = { 0, 1, 0, -1 };
int y_direction[] = { -1, 0, 1, 0 };

void dfs(int y, int x);

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        while (k--) {
            int y, x;
            cin >> y >> x;
            cabbage_exist[y][x] = true;
        }
        
        int answer = 0; // num of areas
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cabbage_exist[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    ++answer;
                }
            }
        }
        
        cout << answer << '\n';
        memset(cabbage_exist, false, sizeof(cabbage_exist));
        memset(visited, false, sizeof(visited));
    }
    
    return 0;
}

void dfs(int y, int x) {
    visited[y][x] = true;
    
    for (int i = 0; i < 4; i++) {
        int next_y = y + y_direction[i];
        int next_x = x + x_direction[i];
        
        if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m
            && cabbage_exist[next_y][next_x] && !visited[next_y][next_x]) {
            dfs(next_y, next_x);
        }
    }
}

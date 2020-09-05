#include <iostream>

using namespace std;

int n;
int max_height = 0;
int max_safe_count = 0;
int height[100][100];
bool visited[100][100];
int x_direction[] = { 0, 1, 0, -1 };
int y_direction[] = { -1, 0, 1, 0 };

void dfs(int x, int y, int rainfall) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int next_x = x + x_direction[i];
        int next_y = y + y_direction[i];
        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
            if (height[next_x][next_y] > rainfall && !visited[next_x][next_y]) {
                dfs(next_x, next_y, rainfall);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            height[i][j] = input;
            if (input > max_height) max_height = input;
        }
    }
    for (int rainfall = 0; rainfall < max_height; rainfall++) {
        int safe_count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (height[i][j] > rainfall && !visited[i][j]) {
                    dfs(i, j, rainfall);
                    ++safe_count;
                }
            }
        }
        if (safe_count > max_safe_count) max_safe_count = safe_count;
    }
    
    cout << max_safe_count <<'\n';
    
    return 0;
}

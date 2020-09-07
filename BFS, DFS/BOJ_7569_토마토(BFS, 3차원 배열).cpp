#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;

int h, n, m; // height, vertical, horizontal
int box[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int x_direction[] = { 0, 0, 1, 0, -1, 0 };
int y_direction[] = { 0, -1, 0, 1, 0, 0 };
int z_direction[] = { -1, 0, 0, 0, 0, 1 };

struct position {
    int z, y, x;
};

int main(int argc, const char * argv[]) {
    cin >> m >> n >> h;
    
    queue<position> q;
    int segment = 0; // num of tomatoes to check in a day
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &box[i][j][k]);
                if (box[i][j][k] == 1) {
                    q.push({ i, j, k });
                    visited[i][j][k] = true;
                    ++segment;
                }
            }
        }
    }
    
    int day = 0;
    while (!q.empty()) {
        int increased_tomatoes = 0;
        for (int i = 0; i < segment; i++) {
            position pos = q.front();
            q.pop();
            
            for (int j = 0; j < 6; j++) {
                int next_x = pos.x + x_direction[j];
                int next_y = pos.y + y_direction[j];
                int next_z = pos.z + z_direction[j];
                
                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && next_z >= 0 && next_z < h
                        && box[next_z][next_y][next_x] == 0 && !visited[next_z][next_y][next_x]) {
                    q.push({next_z, next_y, next_x});
                    box[next_z][next_y][next_x] = 1;
                    visited[next_z][next_y][next_x] = true;
                    ++increased_tomatoes;
                }
            }
        }
        
        segment = increased_tomatoes;
        if (segment) ++day;
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (box[i][j][k] == 0) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }
    
    cout << day << '\n';
    return 0;
}

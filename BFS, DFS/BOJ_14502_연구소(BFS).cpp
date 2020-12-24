#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int EMPTY = 0, WALL = 1, VIRUS = 2;

int n, m;
int map[8][8];
int tmp[8][8];
int dir_r[4] = { 0, 0, 1, -1 }, dir_c[4] = { 1, -1, 0, 0 };
int answer = 0;

void copy_map(int a[][8], int b[][8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            a[i][j] = b[i][j];
    }
}

int cnt_safety_zone(int arr[][8]) {
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (arr[i][j] == EMPTY) ++cnt;
    }
    
    return cnt;
}

void spread_virus() {
    int map_vir[8][8];
    queue<pair<int, int>> q;
    
    copy_map(map_vir, tmp);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map_vir[i][j] == VIRUS) q.push(pair<int, int>(i, j));
        }
    }
            
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dir_r[i], nc = c + dir_c[i];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && map_vir[nr][nc] == EMPTY) {
                q.push(pair<int, int>(nr, nc));
                map_vir[nr][nc] = VIRUS;
            }
        }
    }
    
    answer = max(answer, cnt_safety_zone(map_vir));
}

void build_wall(int cnt) {
    if (cnt == 3) {
        
        spread_virus();
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == EMPTY) {
                if (cnt == 0) copy_map(tmp, map);
                
                tmp[i][j] = WALL;
                build_wall(cnt + 1);
                tmp[i][j] = EMPTY;
            }
        }
    }
}


int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            tmp[i][j] = map[i][j];
        }
    }
    
    build_wall(0);
    cout << answer << '\n';
    
    return 0;
}

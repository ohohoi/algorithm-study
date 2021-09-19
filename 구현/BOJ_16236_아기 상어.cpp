#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int EMP = 0, BABY = 9;
const int MAX = 20;

int n;
int cr, cc;
int baby_size = 2;
int cnt_eat = 0;

int space[MAX][MAX];

int rd[] = { -1, 0, 1, 0 }; // up, right, down, left
int cd[] = { 0, 1, 0, -1 };

struct fish {
    int r;
    int c;
    int dist;
};

bool compare(fish a, fish b) {
    if (a.dist == b.dist) {
        if (a.r == b.r) return a.c < b.c;
        else return a.r < b.r;
    }
    else {
        return a.dist < b.dist;
    }
}

int eat(int r, int c) {
    bool is_visited[n][n];
    
    for (int ri = 0; ri < n; ri++) {
        for (int ci = 0; ci < n; ci++) {
            is_visited[ri][ci] = false;
        }
    }

    queue<fish> q;
    vector<fish> eat_list;
    
    q.push({ r, c, 0 });
    is_visited[r][c] = true;
    
    while (!q.empty()) {
        fish f = q.front();
    
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = f.r + rd[i], nc = f.c + cd[i];
            int s = space[nr][nc];
            
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (is_visited[nr][nc]) continue;
            if (s > baby_size) continue;
            
            q.push({ nr, nc, f.dist + 1 });
            is_visited[nr][nc] = true;
            
            if (s == EMP || s == baby_size) continue;
            
            eat_list.push_back({ nr, nc, f.dist + 1 });
        }
    }
    
    if (eat_list.size() == 0) {
        return 0;
    }
    
    sort(eat_list.begin(), eat_list.end(), compare);
    
    fish closest = eat_list[0];
    
    space[closest.r][closest.c] = EMP;
    cr = closest.r;
    cc = closest.c;
    
    cnt_eat++;
    
    if (cnt_eat == baby_size) {
        baby_size++;
        cnt_eat = 0;
    }
    
    return closest.dist;
}

int main() {
    
    cin >> n;
    
    for (int ri = 0; ri < n; ri++) {
        for (int ci = 0; ci < n; ci++) {
            cin >> space[ri][ci];
            
            if (space[ri][ci] == BABY) {
                cr = ri;
                cc = ci;
                space[ri][ci] = EMP;
            }
        }
    }
    
    int sum_sec = 0;
    
    while (true) {
        int sec = eat(cr, cc);
        
        if (sec == 0) break;
        
        sum_sec += sec;
    }
    
    cout << sum_sec << '\n';
    
    return 0;
}

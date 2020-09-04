/*
 2차원 배열에 미로 저장
 노드를 방문, 방문 표시
 몇 번째에 방문했는지 2차원 배열에 저장
 다음 노드 조건 검사(범위 안에 있는지, 갈 수 있는 노드인지, 방문하지 않은 노드인지)
 */

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    bool can_visit[101][101];
    bool visited[101][101];
    int visit_count[101][101];
    queue<pair<int, int>> queue;
    int x_direction[] = {0, 1, 0, -1};
    int y_direction[] = {-1, 0, 1, 0};
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string tmp;
        
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            can_visit[i][j + 1] = tmp[j] - '0';
        }
    }
    
    visited[1][1] = true;
    queue.push(make_pair(1, 1));
    visit_count[1][1] = 1;
    while (!queue.empty()) {
        pair<int, int> node = queue.front();
        int curr_x = node.first;
        int curr_y = node.second;
        
        queue.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + x_direction[i];
            int next_y = curr_y + y_direction[i];
            
            if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= m) {
                if(!visited[next_x][next_y] && can_visit[next_x][next_y]) {
                    visited[next_x][next_y] = true;
                    queue.push(make_pair(next_x, next_y));
                    visit_count[next_x][next_y] = visit_count[curr_x][curr_y] + 1;
                }
            }
        }
    }
    
    cout << visit_count[n][m] << '\n';
    
    return 0;
}

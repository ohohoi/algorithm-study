#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 100'001;

bool is_visited[MAX];

int main(int argc, const char * argv[]) {
    int s, e;
    
    cin >> s >> e;
    
    queue<pair<int, int>> q;
    
    q.push({s, 0});
    is_visited[s] = true;
    
    int min_cnt = MAX;
    int cnt_case = 0;
    
    while (!q.empty()) {
        int num = q.front().first, cnt = q.front().second;
        
        q.pop();
        is_visited[num] = true;
        
        if (num == e) {
            if (cnt < min_cnt) {
                min_cnt = cnt;
                cnt_case = 1;
            }
            else if (cnt == min_cnt) {
                cnt_case++;
            }
            
            continue;
        }
        
        int next_values[] = {num - 1, num + 1, num * 2};
        
        for (int i = 0; i < 3; i++) {
            int nv = next_values[i];
            
            if (nv < 0 || nv > MAX) continue;
            if (is_visited[nv]) continue;
            
            q.push({nv, cnt + 1});
        }
    }
    
    cout << min_cnt << '\n' << cnt_case << '\n';
    
    return 0;
}

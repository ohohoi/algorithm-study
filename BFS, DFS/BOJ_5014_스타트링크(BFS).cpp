#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000001;
int press_cnt[MAX];
int floors, start, goal, up, down;

int main() {
    cin >> floors >> start >> goal >> up >> down;
    
    if (start == goal) {
        cout << "0\n";
        return 0;
    }
    
    queue<int> q;
    q.push(start);
    press_cnt[start] = 1;

    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (curr == goal) break;
        
        int next_up = curr + up;
        if (next_up >= 1 && next_up <= floors && !press_cnt[next_up]) {
            press_cnt[next_up] = press_cnt[curr] + 1;
            q.push(next_up);
        }
        
        int next_down = curr - down;
        if (next_down >= 1 && next_down <= floors && !press_cnt[next_down]) {
            press_cnt[next_down] = press_cnt[curr] + 1;
            q.push(next_down);
        }
    }
    
    int ans = press_cnt[goal];
    
    if (ans) cout << ans - 1 << '\n';
    else cout << "use the stairs\n";
    
    return 0;
}

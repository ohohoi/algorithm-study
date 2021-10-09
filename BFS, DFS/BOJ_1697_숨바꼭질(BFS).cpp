#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 100'000;

bool is_visited[MAX + 1];

int main(int argc, const char * argv[]) {
    int s, e;
    
    cin >> s >> e;
    
    queue<pair<int, int>> q;
    
    q.push({s, 0});
    is_visited[s] = true;
    
    while (!q.empty()) {
        int n = q.front().first, cnt = q.front().second;
        
        if (n == e) {
            cout << cnt << '\n';
            
            return 0;
        }
        
        q.pop();
        
        int next_values[] = {n - 1, n + 1, n * 2};
        
        for (int i = 0; i < 3; i++) {
            int nv = next_values[i];
            
            if (nv < 0 || nv > MAX) continue;
            if (is_visited[nv]) continue;
            
            q.push({nv, cnt + 1});
            is_visited[nv] = true;
        }
    }
    
    return 0;
}

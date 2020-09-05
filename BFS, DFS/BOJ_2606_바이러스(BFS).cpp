#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 101;
vector<int> adj[MAX];
bool visited[MAX];
int n, m;   // 컴퓨터 개수, 연결 수
int virus_count = 0;

void bfs(int start);

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    
    while (m--) {
        int computer1, computer2;
        cin >> computer1 >> computer2;
        adj[computer1].push_back(computer2);
        adj[computer2].push_back(computer1);
    }
    
    bfs(1);
    cout << virus_count << '\n';
    
    return 0;
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                q.push(adj[node][i]);
                visited[adj[node][i]] = true;
                ++virus_count;
            }
        }
    }
}

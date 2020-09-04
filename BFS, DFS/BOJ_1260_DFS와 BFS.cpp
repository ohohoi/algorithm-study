#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
bool graph[1001][1001];
bool visited[1001];

void dfs(int v);
void bfs(int v);

int main(int argc, const char * argv[]) {
    cin >> n >> m >> v;
    
    while (m--) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1][node2] = graph[node2][node1] = true;
    }
    
    dfs(v);
    cout << '\n';
    
    for (int i = 1; i <= 1000; i++) {
        visited[i] = false;
    }
    
    bfs(v);
    cout << '\n';
    
    return 0;
}

void dfs(int v) {
    visited[v] = true;
    cout << v << ' ';
    for (int i = 1; i <= 1000; i++) {
        if (graph[v][i] == true && !visited[i]) {
            dfs(i);
        }
    }
    
    return;
}

void bfs(int v) {
    queue<int> visited_queue;
    
    visited_queue.push(v);
    visited[v] = true;
    while(!visited_queue.empty()) {
        int node = visited_queue.front();
        
        visited_queue.pop();
        cout << node << ' ';
        for (int i = 1; i <= 1000; i++) {
            if (graph[node][i] == true && !visited[i]) {
                visited_queue.push(i);
                visited[i] = true;
            }
        }
    }
    
    return;
}

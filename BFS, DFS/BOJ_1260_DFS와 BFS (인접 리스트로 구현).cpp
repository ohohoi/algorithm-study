#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1001;
int n, m, v;
vector<int> adj[MAX];
bool visited[MAX];

void dfs(int v);
void bfs(int v);

int main(int argc, const char * argv[]) {
    cin >> n >> m >> v;
    
    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(v);
    cout << '\n';
    
    memset(visited, false, sizeof(visited));
    
    bfs(v);
    cout << '\n';
    
    return 0;
}

void dfs(int v) {
    visited[v] = true;
    cout << v << ' ';
    for (int i = 0; i < adj[v].size(); i++) {
        if (!visited[adj[v][i]]) dfs(adj[v][i]);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    cout << v << ' ';
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                q.push(adj[node][i]);
                visited[adj[node][i]] = true;
                cout << adj[node][i] << ' ';
            }
        }
    }
}

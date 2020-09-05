#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const int MAX = 1001;
vector<int> adj[MAX];
bool visited[MAX];

void dfs(int node);

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int linked_element = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            ++linked_element;
        }
    }
    
    cout << linked_element << '\n';
    
    return 0;
}

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        if (!visited[adj[node][i]]) dfs(adj[node][i]);
    }
}

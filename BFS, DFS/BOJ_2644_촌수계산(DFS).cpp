#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[101];
bool visited[101];
int person1, person2;
int ans = -1;

void dfs(int n, int cnt) {
    visited[n] = true;
    if (n == person2) {
        ans = cnt;
        return;
    }
    
    for (int i = 0; i < adj[n].size(); i++) {
        int next_node = adj[n][i];
        if (!visited[next_node]) dfs(next_node, cnt + 1);
    }
}

int main() {
    int n;
    cin >> n;
    
    cin >> person1 >> person2;
    
    int m;
    cin >> m;
    
    while (m--) {
        int parent, child;
        cin >> parent >> child;
        
        adj[parent].push_back(child);
        adj[child].push_back(parent);
    }
    dfs(person1, 0);
    cout << ans << '\n';
    return 0;
}

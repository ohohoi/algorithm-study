#include <iostream>

using namespace std;

const int MAX = 11;
int n;
int adj[MAX][MAX];
bool visited[MAX];
int min_cost = INT_MAX;

void dfs(int node, int destination, int weight_sum, int visit_count);
bool all_visited();

int main(int argc, const char * argv[]) {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    
    dfs(1, 1, 0, 0);
    cout << min_cost << '\n';
    
    return 0;
}

void dfs(int node, int destination, int weight_sum, int visit_count) {
    if (node == destination && visit_count == n) {
        if (weight_sum < min_cost) min_cost = weight_sum;
        return;
    }
    
    for (int next = 1; next <= n; next++) {
        if (adj[node][next] != 0 && !visited[next]) {
            visited[next] = true;
            if (weight_sum < min_cost)
                dfs(next, destination, weight_sum + adj[node][next], visit_count + 1);
            visited[next] = false;
        }
    }
}

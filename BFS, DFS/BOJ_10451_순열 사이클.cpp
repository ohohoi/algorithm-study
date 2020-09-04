#include <iostream>

using namespace std;

int graph[1001];
bool visited[1001];

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    dfs(graph[node]);
}

int main(int argc, const char * argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int cycle_count = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int input;
            scanf("%d", &input);
            graph[i] = input;
            visited[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                ++cycle_count;
            }
        }
        printf("%d\n", cycle_count);
    }
    
    return 0;
}

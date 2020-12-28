#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LEFT = 0, RIGHT = 1;
const int MAX = 100'001;

vector<int> adj[MAX];
int model[MAX][2];
int is_visited[MAX];
int cnt_visit = 1;

void dfs(int node) {
    is_visited[node] = true;
    model[node][LEFT] = cnt_visit++;

    for(int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (!is_visited[next]) dfs(next);
    }

    model[node][RIGHT] = cnt_visit++;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;

        int input;
        cin >> input;

        while (input != -1) {
            adj[node].push_back(input);
            cin >> input;
        }
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int root;
    cin >> root;

    dfs(root);

    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << model[i][LEFT] << ' ' << model[i][RIGHT] << '\n';
    }
    
    return 0;
}

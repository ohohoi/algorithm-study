#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 100'001;

int max_dist_node = -1;
int max_dist = 0;

vector<pair<int, int>> tree[MAX]; // first: 정점, second: 거리
bool is_visited[MAX];

void dfs(int curr_node, int dist_sum) {
    is_visited[curr_node] = true;
    
    if (dist_sum > max_dist) {
        max_dist = dist_sum;
        max_dist_node = curr_node;
    }
    
    for (int i = 0; i < tree[curr_node].size(); i++) {
        int next_node = tree[curr_node][i].first;
        int next_dist = tree[curr_node][i].second + dist_sum;
        
        if (is_visited[next_node]) continue;
        
        dfs(next_node, next_dist);
    }
}

int main() {
    int v;
    
    cin >> v;
    
    
    for (int vi = 0; vi < v; vi++) {
        int v1, v2;
        
        cin >> v1 >> v2;
        
        while (v2 != -1) {
            int e;
            
            cin >> e;
            
            tree[v1].push_back(make_pair(v2, e));
            
            cin >> v2;
        }
    }
    
    dfs(1, 0);
    
    for (int i = 1; i <= v; i++) {
        is_visited[i] = false;
    }
    
    dfs(max_dist_node, 0);
    
    cout << max_dist << '\n';
    
    return 0;
}

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int v, e;
    int start;
    
    cin >> v >> e >> start;
    
    vector<pair<int, int>> graph[v + 1];    // first: node number, second: weight
    
    for (int i = 0; i < e; i++) {
        int u, v, w;
        
        cin >> u >> v >> w;
        
        graph[u].push_back({v, w});
    }
    
    // dijkstra
    int distance[v + 1];
    priority_queue<pair<int, int>> pq;  // first: weight, second: node number
    
    for (int i = 1; i <= v; i++) {
        distance[i] = INT_MAX;
    }
    
    distance[start] = 0;
    pq.push({distance[start], start});
    
    while(!pq.empty()) {
        int dist_sum = -pq.top().first;
        int curr_node = pq.top().second;
        
        pq.pop();
        
        if (dist_sum > distance[curr_node]) {
            continue;
        }
        
        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i].first;
            int weight = graph[curr_node][i].second;
            
            if (dist_sum + weight < distance[next_node]) {
                distance[next_node] = dist_sum + weight;
                pq.push({-distance[next_node], next_node});
            }
        }
    }
    
    for (int i = 1; i <= v; i++) {
        if (distance[i] == INT_MAX) {
            cout << "INF\n";
        }
        else {
            cout << distance[i] << '\n';
        }
    }
    
    return 0;
}

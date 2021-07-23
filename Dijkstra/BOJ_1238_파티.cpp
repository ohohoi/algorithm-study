#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

const int GO = 0, BACK = 1;

int main() {
    int nodes, edges, dest;
    
    cin >> nodes >> edges >> dest;
    
    vector<pair<int, int>> graph[nodes + 1];   // first: node number, second: weight
    
    for (int i = 0; i < edges; i++) {
        int s, e, w;
        
        cin >> s >> e >> w;
        
        graph[s].push_back({e, w});
    }
    
    int max_dist = 0;
    
    for (int ni = 1; ni <= nodes; ni++) {
        int dist[nodes + 1][2]; // 0: go, 1: come back
        
        for (int i = 1; i <= nodes; i++) {
            dist[i][GO] = dist[i][BACK] = INT_MAX;
        }
        
        for (int go_or_back = 0; go_or_back <= 1; go_or_back++) {
            priority_queue<pair<int, int>> pq; // first: distance, second: node number
            
            if (go_or_back == GO) {
                dist[ni][go_or_back] = 0;
                pq.push({0, ni});
            }
            else if (go_or_back == BACK) {
                dist[dest][go_or_back] = 0;
                pq.push({0, dest});
            }
            
            while (!pq.empty()) {
                int curr_node = pq.top().second;
                int distance = -pq.top().first;
                
                pq.pop();
                
                if (distance > dist[curr_node][go_or_back]) {
                    continue;
                }
                
                for (int gi = 0; gi < graph[curr_node].size(); gi++) {
                    int next_node = graph[curr_node][gi].first;
                    int weight = graph[curr_node][gi].second;
                    
                    if (distance + weight < dist[next_node][go_or_back]) {
                        dist[next_node][go_or_back] = distance + weight;
                        pq.push({-dist[next_node][go_or_back], next_node});
                    }
                }
            }
        }
        
        int dist_sum = dist[dest][GO] + dist[ni][BACK];
        
        if (dist_sum > max_dist) {
            max_dist = dist_sum;
        }
    }
    
    cout << max_dist << '\n';
    
    return 0;
}

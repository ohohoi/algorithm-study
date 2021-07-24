#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void dijkstra(int n, int s, int dist[n + 1], vector<pair<int, int>> graph[]) {  // return dist array
    priority_queue<pair<int, int>> pq;  // first: dist, second: node number
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    
    dist[s] = 0;
    pq.push({0, s});
    
    while(!pq.empty()) {
        int curr_node = pq.top().second;
        int distance = -pq.top().first;
        
        pq.pop();
        
        if (distance > dist[curr_node]) {
            continue;
        }
        
        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i].first;
            int weight = graph[curr_node][i].second;
            
            if (distance + weight < dist[next_node]) {
                dist[next_node] = distance + weight;
                pq.push({-dist[next_node], next_node});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<pair<int, int>> graph[n + 1];    // first: node number, second: fare
    
    for (int i = 0; i < fares.size(); i++) {
        int node1 = fares[i][0];
        int node2 = fares[i][1];
        int fare = fares[i][2];
        
        graph[node1].push_back(pair<int, int>(node2, fare));
        graph[node2].push_back(pair<int, int>(node1, fare));
    }
    
    int min_fare = INT_MAX;
    int dist[n + 1];
    
    dijkstra(n, s, dist, graph);
    
    for (int sep_node = 1; sep_node <= n; sep_node++) {
        int dist_sep[n + 1];
        
        dijkstra(n, sep_node, dist_sep, graph);
        
        int fare_sum = dist[sep_node] + dist_sep[a] + dist_sep[b];
        
        if (fare_sum < min_fare) {
            min_fare = fare_sum;
        }
    }
    
    return min_fare;
}

int main() {
    int n[] = {6, 7, 6}, s[] = {4, 3, 4}, a[] = {6, 4, 5}, b[] = {2, 1, 6};
    vector<vector<int>> fares[3] = {
        {
            {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66},{2, 3, 22}, {1, 6, 25}
        },
        {
            {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}
        },
        {
            {2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}
        }
    };
    
    for (int i = 0; i < 3; i++) {
        int answer = solution(n[i], s[i], a[i], b[i], fares[i]);
        
        cout << "answer: " << answer << '\n';
    }
    
    return 0;
}

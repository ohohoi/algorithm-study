#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

int rDir[] = {-1, 0, 1, 0}; // up, right, down, left
int cDir[] = {0, 1, 0, -1};

int main() {
    int r, c;
    
    cin >> c >> r;
    
    int maze[r][c];
    vector<pair<int, int>> wall[r * c]; // node number, wall exists
    
    for (int ri = 0; ri < r; ri++) {
        char input[c];
        
        cin >> input;
        
        for (int ci = 0; ci < c; ci++) {
            maze[ri][ci] = input[ci] - '0';
        }
    }
    
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            for (int i = 0; i < 4; i++) {
                int nr = ri + rDir[i];
                int nc = ci + cDir[i];
                int curr_node = ri * c + ci;
                int next_node = nr * c + nc;
                
                if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                    continue;
                }
                
                wall[curr_node].push_back({next_node, maze[nr][nc]});
            }
        }
    }
    
    // dijkstra
    priority_queue<pair<int, int>> pq;  // distance, node number
    int dist[r * c];

    for (int i = 0; i < r * c; i++) {
        dist[i] = INT_MAX;
    }

    dist[0] = 0;
    pq.push({dist[0], 0});

    while(!pq.empty()) {
        int curr_node = pq.top().second;
        int cnt_dist = -pq.top().first;

        pq.pop();
        
        if (cnt_dist > dist[curr_node]) {
            continue;
        }

        for (int i = 0; i < wall[curr_node].size(); i++) {
            int next_node = wall[curr_node][i].first;
            int weight = wall[curr_node][i].second;

            if (cnt_dist + weight < dist[next_node]) {
                dist[next_node] = cnt_dist + weight;
                pq.push({-dist[next_node], next_node});
            }
        }
    }

    cout << dist[r * c - 1] << '\n';
    
    return 0;
}

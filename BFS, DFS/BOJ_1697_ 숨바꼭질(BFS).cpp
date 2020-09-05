#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
int visited_count[MAX];

int bfs(int start, int destination);

int main(int argc, const char * argv[]) {
    int n, k;
    
    cin >> n >> k;
    
    cout << bfs(n, k) << '\n';;
    
    return 0;
}

int bfs(int start, int destination) {
    if (start == destination) return 0;
    
    queue<int> q;
    q.push(start);
    visited_count[start] = 0;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        if (node == destination) return visited_count[node];
        
        int next = node - 1;
        if (next >= 0 && visited_count[next] == 0) {
            q.push(next);
            visited_count[next] = visited_count[node] + 1;
        }
        
        next = node + 1;
        if (next <= 100000 && visited_count[next] == 0) {
            q.push(next);
            visited_count[next] = visited_count[node] + 1;
        }
        
        next = node * 2;
        if (next <= 100000 && visited_count[next] == 0) {
            q.push(next);
            visited_count[next] = visited_count[node] + 1;
        }
    }
    
    return 0;
}

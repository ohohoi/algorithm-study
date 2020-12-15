#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10'001;
const int IN = 0, OUT = 1;

int n;
int weight[MAX];
vector<int> adj[MAX];
int dp[MAX][2];
vector<int> ind_set;

void dpdfs(int v, int parent) {
    for (int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] != parent) dpdfs(adj[v][i], v);
    }
    
    dp[v][IN] = weight[v];
    dp[v][OUT] = 0;
    
    for (int i = 0; i < adj[v].size(); i++) {
        dp[v][IN] += dp[adj[v][i]][OUT];
        dp[v][OUT] += max(dp[adj[v][i]][IN], dp[adj[v][i]][OUT]);
    }
}

void trace(int v, int parent, int in) {
    if (in == IN) {
        ind_set.push_back(v);
    
        for (int i = 0; i < adj[v].size(); i++) {
            if (adj[v][i] == parent) continue;
            
            trace(adj[v][i], v, OUT);
        }
    }
    else {
        for (int i = 0; i < adj[v].size(); i++) {
            if (adj[v][i] == parent) continue;
            
            if (dp[adj[v][i]][IN] > dp[adj[v][i]][OUT]) trace(adj[v][i], v, IN);
            else trace(adj[v][i], v, OUT);
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        cin >> weight[i];
    
    for (int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    
    dpdfs(1, 0);
    
    if (dp[1][IN] > dp[1][OUT]) {
        cout << dp[1][IN] << '\n';
        trace(1, 0, IN);
    }
    else {
        cout << dp[1][OUT] << '\n';
        trace(1, 0, OUT);
    }
    
    sort(ind_set.begin(), ind_set.end());
    for (int i = 0; i < ind_set.size(); i++) cout << ind_set[i] << ' ';
    
    return 0;
}

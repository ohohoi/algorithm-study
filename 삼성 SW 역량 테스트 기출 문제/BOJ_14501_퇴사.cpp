#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX = 16;
vector<pair<int, int>> schedule[MAX];
int dp[MAX];

int main() {
    int n;
    scanf("%d", &n);
    
    for (int start_time = 1; start_time <= n; start_time++) {
        int time, price;
        scanf("%d %d", &time, &price);
        
        int end_time = start_time + time - 1;
        if (end_time > n) continue;
        
        schedule[end_time].push_back(pair<int, int>(start_time, price));
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < schedule[i].size(); j++) {
            int start_time = schedule[i][j].first;
            int price = schedule[i][j].second;
            int price_sum = dp[start_time - 1] + price;
            if (price_sum > dp[i]) dp[i] = price_sum;
        }
    }
    
    printf("%d\n", dp[n]);
    return 0;
}

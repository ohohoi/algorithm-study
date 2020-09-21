#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][100'001];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int weight[n + 1];
    int value[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", weight + i, value + i);
    }
    
    for (int i = 1; i <= n; i++) {
        int w = weight[i];
        int v = value[i];
        for (int j = 1; j <= k; j++) {
            if (j < w) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
        }
    }
    
    printf("%d\n", dp[n][k]);
    return 0;
}

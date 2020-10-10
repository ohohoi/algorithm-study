#include <iostream>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int candy[n][m];
    int dp[n][m];
    int row[3] = {-1, 0, -1};
    int col[3] = {0, -1, -1};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &candy[i][j]);
            dp[i][j] = candy[i][j];
            
            for (int k = 0; k < 3; k++) {
                int r = i + row[k], c = j + col[k];
                if (r >= 0 && c >= 0 && candy[i][j] + dp[r][c] > dp[i][j])
                    dp[i][j] = candy[i][j] + dp[r][c];
            }
        }
    }
    
    printf("%d\n", dp[n - 1][m - 1]);
    return 0;
}

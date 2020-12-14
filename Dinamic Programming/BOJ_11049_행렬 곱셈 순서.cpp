#include <iostream>
#include <cstring>

using namespace std;

const int R = 0, C = 1;

int main() {
    int n;
    scanf("%d", &n);
    
    int matrix[n][2];
    int dp[n][n];
    
    for (int i = 0; i < n; i++)
        scanf("%d %d", &matrix[i][R], &matrix[i][C]);
    
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = matrix[i][R] * matrix[i][C] * matrix[i + 1][C];
    
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            dp[j][j + i] = 0x7fffffff;
            
            for (int k = j; k < j + i; k++) {
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + matrix[j][R] * matrix[k][C] * matrix[j + i][C]);
            }
        }
    }
    
    printf("%d\n", dp[0][n - 1]);
    return 0;
}

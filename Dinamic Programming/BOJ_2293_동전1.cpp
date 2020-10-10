#include <iostream>
#include <cstring>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int coin[n];
    for (int i = 0; i < n; i++)
        scanf("%d", coin + i);
    
    int dp[k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
        }
    }

    printf("%d\n", dp[k]);
    return 0;
}

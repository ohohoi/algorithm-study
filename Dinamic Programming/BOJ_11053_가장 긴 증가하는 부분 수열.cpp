#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> nums(n);;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    vector<int> dp(n); // store num of LIS
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] >= dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max) max = dp[i];
    }
    
    printf("%d\n", max);
    return 0;
}

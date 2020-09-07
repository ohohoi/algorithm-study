#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n; // number to make to 1
    int dp[1000001]; // array to store min count
    
    cin >> n;
    dp[1] = 0;
    
    for (int i = 2; i <= n; i++) {
        int min_count = 0x7fffffff;
        
        if (i % 3 == 0 && 1 + dp[i / 3] < min_count)
            min_count = 1 + dp[i / 3];
        
        if (i % 2 == 0 && 1 + dp[i / 2] < min_count)
            min_count = 1 + dp[i / 2];
        
        if (1 + dp[i - 1] < min_count) min_count = 1 + dp[i - 1];
        
        dp[i] = min_count;
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}

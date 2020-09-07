#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2; // dp[1] + 1
        dp[3] = 4; // dp[1] + dp[2] + 1
        
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        
        cout << dp[n] << '\n';
    }
    
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int sum[n + 1][2]; //[i][0]: 전전 계단에서 온 경우, [i][1]: 이전 계단에서 온 경우
    
    memset(sum, 0, sizeof(sum));
    scanf("%d", &sum[1][0]);
    
    for (int i = 2; i <= n; i++) {
        int score;
        scanf("%d", &score);
        
        sum[i][0] = score + max(sum[i - 2][0], sum[i - 2][1]);
        sum[i][1] = score + sum[i - 1][0];
    }

    printf("%d\n", max(sum[n][0], sum[n][1]));
    
    return 0;
}

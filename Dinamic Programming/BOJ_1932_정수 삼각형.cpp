#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int triangle[n];
    int sum[n];
    
    memset(sum, 0, sizeof(sum));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            scanf("%d", &triangle[j]);
        }
        
        int tmp[i];
        for (int j = 0; j < i; j++) {
            if (j == 0)
                tmp[j] = triangle[j] + sum[j];
            else
                tmp[j] = triangle[j] + max(sum[j - 1], sum[j]);
        }
        
        for (int j = 0; j < i; j++) {
            sum[j] = tmp[j];
        }
    }
    
    int max = 0;
    
    for (int i = 0; i < n; i++) {
        if (sum[i] > max) max = sum[i];
    }
    
    printf("%d\n", max);
    
    return 0;
}

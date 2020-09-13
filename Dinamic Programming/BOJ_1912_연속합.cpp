#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    
    int sum;
    scanf("%d", &sum);
    
    int max = sum;
    
    for (int i = 1; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (sum > 0) sum += num;
        else sum = num;
        
        if (sum > max) max = sum;
    }
    
    printf("%d\n", max);
    return 0;
}

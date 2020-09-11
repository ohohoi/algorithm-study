#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    
    int before1 = 1;
    int before2 = 1;
    int fib = 1;
    
    for (int i = 2; i <= n; i++) {
        fib = (before1 + before2) % 15746;
        before1 = before2;
        before2 = fib;
    }
    
    printf("%d\n", fib);
    
    return 0;
}

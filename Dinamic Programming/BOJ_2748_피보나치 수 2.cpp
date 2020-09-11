#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    long long before1 = 0;
    long long before2 = 1;
    long long fib = 1;
    
    for (int i = 2; i <= n; i++) {
        fib = before1 + before2;
        before1 = before2;
        before2 = fib;
    }
    
    printf("%lld\n", fib);
    
    return 0;
}

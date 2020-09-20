#include <iostream>

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    
    int sequence[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }
    
    int start = 0, end = 0;
    int sum = 0;
    int min_length = 0x7fffffff;
    
    while (start < n) {
        if (sum >= s || end == n) {
            if (sum >= s) {
                int length = end - start;
                if (length < min_length) min_length = length;
            }
            sum -= sequence[start++];
        }
        else {
            sum += sequence[end++];
        }
    }
    
    printf("%d\n", min_length != 0x7fffffff ? min_length : 0);
    return 0;
}

#include <iostream>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    int s = 0, e = 0;
    int subsum = 0;
    int cnt = 0;
    while (s < n) {
        if (subsum == m) ++cnt;
        if (subsum >= m) subsum -= num[s++];
        else subsum += num[e++];
    }
    
    printf("%d\n", cnt);
    
    return 0;
}

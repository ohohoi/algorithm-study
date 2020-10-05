#include <iostream>

const int MAX = 30;
int num_of_cases[MAX][MAX];

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i <= m; i++) {
            num_of_cases[0][i] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= m; j++) {
                num_of_cases[i][j] = 0;
                
                for (int k = j - 1; k >= i - 1; k--) {
                    num_of_cases[i][j] += num_of_cases[i - 1][k];
                }
            }
        }
        
        printf("%d\n", num_of_cases[n][m]);
    }
    
    return 0;
}

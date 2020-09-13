#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    vector<vector<int>> lines(n);
    for (int i = 0; i < n; i++) {
        lines[i] = vector<int>(2);
        scanf("%d %d", &lines[i][0], &lines[i][1]);
    }
    
    sort(lines.begin(), lines.end());
    
    int lis[n];
    int max = 0;
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (lines[j][1] < lines[i][1] && lis[j] >= lis[i])
                lis[i] = lis[j] + 1;
        }
        if (lis[i] > max) max = lis[i];
    }
    
    printf("%d\n", n - max);
    return 0;
}

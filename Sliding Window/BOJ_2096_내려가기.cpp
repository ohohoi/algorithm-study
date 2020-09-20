#include <iostream>
#include <algorithm>

using namespace std;

int dp_max[3];
int dp_min[3];

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        int input[3];
        int tmp_max[3];
        int tmp_min[3];
        scanf("%d %d %d", &input[0], &input[1], &input[2]);

        tmp_max[0] = input[0] + max(dp_max[0], dp_max[1]);
        tmp_max[1] = input[1] + max(dp_max[0], max(dp_max[1], dp_max[2]));
        tmp_max[2] = input[2] + max(dp_max[1], dp_max[2]);
        
        tmp_min[0] = input[0] + min(dp_min[0], dp_min[1]);
        tmp_min[1] = input[1] + min(dp_min[0], min(dp_min[1], dp_min[2]));
        tmp_min[2] = input[2] + min(dp_min[1], dp_min[2]);
        
        for (int i = 0; i < 3; i++) {
            dp_max[i] = tmp_max[i];
            dp_min[i] = tmp_min[i];
        }
    }
    
    printf("%d %d\n", max(dp_max[0], max(dp_max[1], dp_max[2])), min(dp_min[0], min(dp_min[1], dp_min[2])));
    
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

const int R = 0;
const int G = 1;
const int B = 2;
int cost[3];

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int rgb[3];
        scanf("%d %d %d", &rgb[R], &rgb[G], &rgb[B]);
        
        int tmp[3];
        tmp[R] = rgb[R] + min(cost[G], cost[B]);
        tmp[G] = rgb[G] + min(cost[R], cost[B]);
        tmp[B] = rgb[B] + min(cost[R], cost[G]);
        
        cost[R] = tmp[R];
        cost[G] = tmp[G];
        cost[B] = tmp[B];
    }
    
    printf("%d\n", min(cost[R], min(cost[G], cost[B])));
    
    return 0;
}

#include <iostream>

const int MAX = 201;
int parent[MAX];
int height[MAX];

int find(int x);
void union_set(int x, int y);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int connected;
            scanf("%d", &connected);
            if (j >= i && connected) {
                union_set(i, j);
            }
        }
    }
    
    int city;
    scanf("%d", &city);
    int root = find(city);
    
    while(--m) {
        int city;
        scanf("%d", &city);
        if (find(city) != root) {
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
    return 0;
}

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (height[x] > height[y]) parent[y] = x;
    else {
        parent[x] = y;
        if (height[x] == height[y]) height[y]++;
    }
}

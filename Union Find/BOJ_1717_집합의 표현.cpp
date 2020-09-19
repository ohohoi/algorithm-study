#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> height;

int find(int x);
void union_set(int x, int y);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    parent.resize(n + 1);
    height.resize(n + 1);
    
    //initialize
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        height[i] = 0;
    }
    
    while (m--) {
        int cmd, a, b;
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd) { //find
            if (find(a) == find(b)) printf("YES\n");
            else printf("NO\n");
        }
        else { //union
            union_set(a, b);
        }
    }
    return 0;
}

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    if (height[x] > height[y])
        parent[y] = x;
    else {
        parent[x] = y;
        if (height[x] == height[y])
            height[y]++;
    }
}

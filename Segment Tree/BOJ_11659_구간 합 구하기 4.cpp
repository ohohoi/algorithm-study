#include <iostream>

int numbers[100001];
int segment_tree[400000];

int init(int node, int first, int last);
int sum(int left, int right, int node, int first, int last);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    init(1, 1, n);
    
    while (m--) {
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d\n", sum(left, right, 1, 1, n));
    }
    
    return 0;
}

int init(int node, int first, int last) {
    if (first == last) return segment_tree[node] = numbers[first];
    int mid = (first + last) / 2;
    return segment_tree[node] = init(node * 2, first, mid) + init(node * 2 + 1, mid + 1, last);
}

int sum(int left, int right, int node, int first, int last) {
    if (first > right || last < left) return 0;
    if (first >= left && last <= right) return segment_tree[node];
    int mid = (first + last) / 2;
    return sum(left, right, node * 2, first, mid) + sum(left, right, node * 2 + 1, mid + 1, last);
}

#include <iostream>

int numbers[100001];
int segment_tree[400000];

int init(int node, int first, int last);
int find(int node, int first, int last, int left, int right);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    init(1, 1, n);
    
    while (m--) {
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d\n", find(1, 1, n, left, right));
    }
    
    return 0;
}

int init(int node, int first, int last) {
    if (first == last) return segment_tree[node] = numbers[first];
    
    int mid = (first + last) / 2;
    int left_child = init(node * 2, first, mid);
    int right_child = init(node * 2 + 1, mid + 1, last);
    
    if (left_child < right_child) return segment_tree[node] = left_child;
    else return segment_tree[node] = right_child;
}

int find(int node, int first, int last, int left, int right) {
    if (first > right || last < left) return 0x7fffffff;
    if (first >= left && last <= right) return segment_tree[node];
    
    int mid = (first + last) / 2;
    int left_child = find(node * 2, first, mid, left, right);
    int right_child = find(node * 2 + 1, mid + 1, last, left, right);
    
    if (left_child < right_child) return left_child;
    else return right_child;
}

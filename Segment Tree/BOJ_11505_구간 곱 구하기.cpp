#include <iostream>
#include <cmath>

const int MOD_VALUE = 1000000007;
int numbers[1000001];
long long segment_tree[4000000];

long long init(int node, int first, int last) {
    if (first == last) return segment_tree[node] = numbers[first] % MOD_VALUE;
    int mid = (first + last) / 2;
    return segment_tree[node] = (init(node * 2, first, mid) * init(node * 2 + 1, mid + 1, last)) % MOD_VALUE;
}

long long update(int index, int update_value, int node, int first, int last) {
    if (index < first || index > last) return segment_tree[node];
    if (first == last) return segment_tree[node] = update_value;
    int mid = (first + last) / 2;
    return segment_tree[node] = (update(index, update_value, node * 2, first, mid) * update(index, update_value, node * 2 + 1, mid + 1, last)) % MOD_VALUE;
}

long long multiply(int left, int right, int node, int first, int last) {
    if (first > right || last < left) return 1;
    if (first >= left && last <= right) return segment_tree[node];
    int mid = (first + last) / 2;
    return (multiply(left, right, node * 2, first, mid) * multiply(left, right, node * 2 + 1, mid + 1, last)) % MOD_VALUE;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    int h = (int)ceil(log2(n)) + 1;
    int size = 1 << h;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    init(1, 1, n);
    
    for (int i = 0; i < k + m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            numbers[b] = c;
            update(b, c, 1, 1, n);
        }
        else {
            printf("%lld\n", multiply(b, c, 1, 1, n));
        }
    }
    
    return 0;
}

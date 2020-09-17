#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> numbers;
vector<long long> segment_tree;

long long init(int node, int first, int last);
void update(int index, long long diff, int node, int first, int last);
long long sum(int left, int right, int node, int first, int last);

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    int height = (int)ceil(log2(n)) + 1;
    int size = 1 << height;
    
    numbers.resize(n + 1);
    segment_tree.resize(size);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &numbers[i]);
    }
    
    init(1, 1, n);
    
    for (int i = 0; i < m + k; i++) {
        int a, b;
        scanf("%d", &a);
        if (a == 1) {
            long long c;
            scanf("%d %lld", &b, &c);
            long long diff = c - numbers[b];
            numbers[b] = c;
            update(b, diff, 1, 1, n);
        }
        else {
            int c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", sum(b, c, 1, 1, n));
        }
    }
    
    return 0;
}

long long init(int node, int first, int last) {
    if (first == last) return segment_tree[node] = numbers[first];
    int mid = (first + last) / 2;
    return segment_tree[node] = init(node * 2, first, mid) + init(node * 2 + 1, mid + 1, last);
}

void update(int index, long long diff, int node, int first, int last) {
    if (index < first || index > last) return;
    segment_tree[node] += diff;
    if (first != last) {
        int mid = (first + last) / 2;
        update(index, diff, node * 2, first, mid);
        update(index, diff, node * 2 + 1, mid + 1, last);
    }
}

long long sum(int left, int right, int node, int first, int last) {
    if (first > right || last < left) return 0;
    if (first >= left && last <= right) return segment_tree[node];
    int mid = (first + last) / 2;
    return sum(left, right, node * 2, first, mid) + sum(left, right, node * 2 + 1, mid + 1, last);
}

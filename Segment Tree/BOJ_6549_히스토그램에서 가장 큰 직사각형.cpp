#include <iostream>

int n;
int h[100000];
int segment_tree[400000];

int init(int node, int first, int last);
int get_min_index(int node, int first, int last, int left, int right);
long long get_max_area(int left, int right);

int main() {
    while (true) {
        scanf("%d", &n);
        
        if (n == 0) return 0;
        
        for (int i = 0; i <= n - 1; i++) {
            scanf("%d", h + i);
        }
        
        init(1, 0, n - 1);
        printf("%lld\n", get_max_area(0, n - 1));
    }
    
    return 0;
}

int init(int node, int first, int last) {
    if (first == last) return segment_tree[node] = first;
    
    int mid = (first + last) / 2;
    int left_min_index = init(node * 2, first, mid);
    int right_min_index = init(node * 2 + 1, mid + 1, last);
    
    return segment_tree[node] = h[left_min_index] < h[right_min_index] ? left_min_index : right_min_index;
}

int get_min_index(int node, int first, int last, int left, int right) {
    if (first > right || last < left) return -1;
    if (first >= left && last <= right) return segment_tree[node];
    
    int mid = (first + last) / 2;
    int left_min_index = get_min_index(node * 2, first, mid, left, right);
    int right_min_index = get_min_index(node * 2 + 1, mid + 1, last, left, right);
    
    if (left_min_index == -1) return right_min_index;
    if (right_min_index == -1) return left_min_index;
    
    return h[left_min_index] < h[right_min_index] ? left_min_index : right_min_index;
}

long long get_max_area(int left, int right) {
    int min_index = get_min_index(1, 0, n - 1, left, right);
    long long max_area = (long long)h[min_index] * (long long)(right - left + 1);
    
    if (left < min_index) {
        long long left_area = get_max_area(left, min_index - 1);
        if (left_area > max_area) max_area = left_area;
    }
    
    if (right > min_index) {
        long long right_area = get_max_area(min_index + 1, right);
        if (right_area > max_area) max_area = right_area;
    }
    
    return max_area;
}

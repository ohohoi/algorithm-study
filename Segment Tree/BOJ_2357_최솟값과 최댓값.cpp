#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> numbers;
vector<pair<int, int>> segment_tree;

pair<int, int> init(int node, int first, int last);
pair<int, int> min_and_max(int left, int right, int node, int first, int last);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int height = (int)ceil(log2(n)) + 1;
    int tree_size = 1 << height;
    
    numbers.resize(n + 1);
    segment_tree.resize(tree_size);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    init(1, 1, n);
    
    while (m--) {
        int left, right;
        scanf("%d %d", &left, &right);
        pair<int, int> result = min_and_max(left, right, 1, 1, n);
        printf("%d %d\n", result.first, result.second);
    }
    
    return 0;
}

pair<int, int> init(int node, int first, int last) {
    if (first == last) return segment_tree[node] = pair<int, int>(numbers[first], numbers[first]);
    
    int mid = (first + last) / 2;
    
    pair<int, int> left_child = init(node * 2, first, mid);
    pair<int, int> right_child = init(node * 2 + 1, mid + 1, last);
    
    int min, max;
    
    if (left_child.first < right_child.first) min = left_child.first;
    else min = right_child.first;
    
    if (left_child.second > right_child.second) max = left_child.second;
    else max = right_child.second;
    
    return segment_tree[node] = pair<int, int>(min, max);
}

pair<int, int> min_and_max(int left, int right, int node, int first, int last) {
    if (first > right || last < left) return pair<int, int>(0x7fffffff, 0x80000000);
    if (first >= left && last <= right) return segment_tree[node];
    
    int mid = (first + last) / 2;
    
    pair<int, int> left_child = min_and_max(left, right, node * 2, first, mid);
    pair<int, int> right_child = min_and_max(left, right, node * 2 + 1, mid + 1, last);
    
    int min, max;
    
    if (left_child.first < right_child.first) min = left_child.first;
    else min = right_child.first;
    
    if (left_child.second > right_child.second) max = left_child.second;
    else max = right_child.second;
    
    return pair<int, int>(min, max);
}

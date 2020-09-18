#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

vector<int> shelves;
vector<pair<int, int>> segment_tree;

pair<int, int> init(int node, int first, int last);
pair<int, int> update(int index, int node, int first, int last);
pair<int, int> min_and_max(int left, int right, int node, int first, int last);

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        
        int tree_heigt = (int)ceil(log2(n)) + 1;
        int tree_size = 1 << tree_heigt;
        
        shelves.resize(n);
        segment_tree.resize(tree_size);
        
        for (int i = 0; i < n; i++) {
            shelves[i] = i;
        }
        
        init(1, 0, n - 1);
        
        while (k--) {
            int q, a, b;
            scanf("%d %d %d", &q, &a, &b);
            if (q) {
                pair<int, int> result = min_and_max(a, b, 1, 0, n - 1);
                if (result.first == a && result.second == b) printf("YES\n");
                else printf("NO\n");
            }
            else {
                int tmp = shelves[a];
                shelves[a] = shelves[b];
                shelves[b] = tmp;
                update(a, 1, 0, n - 1);
                update(b, 1, 0, n - 1);
            }
        }
        
        shelves.clear();
        segment_tree.clear();
    }
    return 0;
}

pair<int, int> init(int node, int first, int last) {
    if (first == last) return segment_tree[node] = pair<int, int>(shelves[first], shelves[first]);
    
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

pair<int, int> update(int index, int node, int first, int last) {
    if (index < first || index > last) return segment_tree[node];
    if (first == last) return segment_tree[node] = pair<int, int>(shelves[first], shelves[first]);
    
    int mid = (first + last) / 2;
    pair<int, int> left_child = update(index, node * 2, first, mid);
    pair<int, int> right_child = update(index, node * 2 + 1, mid + 1, last);
    
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

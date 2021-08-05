#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, mid;
    
    cin >> n >> mid;
    
    int answer[n];
    
    answer[0] = mid;
    
    priority_queue<int> max_heap;
    priority_queue<int> min_heap;
    
    for (int i = 1; i < n; i++) {
        int input;
        
        cin >> input;
        
        if (input < mid) {
            max_heap.push(input);
        }
        else {
            min_heap.push(-input);
        }
        
        int max_heap_size = max_heap.size();
        int min_heap_size = min_heap.size();
        
        if (max_heap_size > min_heap_size) {
            int cnt_move = (max_heap_size - min_heap_size + 1) / 2;
            
            for (int i = 0; i < cnt_move; i++) {
                min_heap.push(-mid);
                mid = max_heap.top();
                max_heap.pop();
            }
        }
        else {
            int cnt_move = (min_heap_size - max_heap_size) / 2;
            for (int i = 0; i < cnt_move; i++) {
                max_heap.push(mid);
                mid = -min_heap.top();
                min_heap.pop();
            }
        }
        
        answer[i] = mid;
    }
    
    for (int i = 0; i < n; i++) {
        cout << answer[i] << '\n';
    }
    
    return 0;
}

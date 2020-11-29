#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int answer;

void bin_search(int arr[], int first, int last) {
    if (first > last) return;
    
    int mid = (first + last) / 2;
    int lesson_idx = 0;
    
    for (int bluray_idx = 0; bluray_idx < m; bluray_idx++) {
        int length = 0;
        
        while (lesson_idx < n && length + arr[lesson_idx] <= mid) {
            length += arr[lesson_idx++];
        }
    }
    
    if (lesson_idx == n) {
        if (mid < answer) answer = mid;
        bin_search(arr, first, mid - 1);
    }
    else {
        bin_search(arr, mid + 1, last);
    }
}

int main() {
    cin >> n >> m;
    
    int lesson_sum = 0;
    int lessons[n];
    
    for (int i = 0; i < n; i++) {
        cin >> lessons[i];
        lesson_sum += lessons[i];
    }
    
    answer = lesson_sum;
    bin_search(lessons, 1, lesson_sum);
    cout << answer << '\n';
    
    return 0;
}

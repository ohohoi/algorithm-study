#include <iostream>
#include <algorithm>

using namespace std;

int k, n;
int answer = 0;

void bin_search(long long arr[], int target, long long start, long long end) {
    if (start > end) return;
    
    long long mid = (start + end) / 2;

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += arr[i] / mid;
    }
    
    if (cnt >= target) {
        if (mid > answer) answer = mid;
        bin_search(arr, target, mid + 1, end);
    }
    else {
        bin_search(arr, target, start, mid - 1);
    }
}

int main() {
    cin >> k >> n;
    
    long long lines[k];
    long long start = 1;
    long long end = 1;
    
    for (int i = 0; i < k; i++) {
        cin >> lines[i];
        if (lines[i] > end) end = lines[i];
    }
    
    bin_search(lines, n, start, end);
    cout << answer << '\n';
    
    return 0;
}

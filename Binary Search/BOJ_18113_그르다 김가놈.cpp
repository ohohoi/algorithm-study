#include <iostream>

using namespace std;

int n, k, m;
int answer = -1;

bool check(int arr[], int p) {
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 2 * k) {
            cnt += (arr[i] - 2 * k) / p;
        }
        else if (arr[i] > k) {
            cnt += (arr[i] - k) / p;
        }
    }
    
    if (cnt >= m) return true;
    else return false;
}

void bin_search(int arr[], int start, int end) {
    if (start > end) return;
    
    int mid = (start + end) / 2;
    
    if (check(arr, mid)) {
        if (answer < mid) answer = mid;
        bin_search(arr, mid + 1, end);
    }
    else {
        bin_search(arr, start, mid - 1);
    }
}

int main() {
    cin >> n >> k >> m;
    
    int kimbap[n];
    int max_len = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> kimbap[i];
        if (kimbap[i] > max_len) max_len = kimbap[i];
    }
    
    bin_search(kimbap, 1, max_len);
    cout << answer << '\n';
    
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
int answer = 1;

bool possible(int house[], int mid) {
    int prev = house[0];
    int cnt = 1;
    
    for (int i = 1; i < n; i++) {
        int curr = house[i];
        
        if (curr - prev >= mid) {
            ++cnt;
            prev = curr;
            
            if (cnt == c) return true;
        }
    }
    
    return false;
}

void bin_search(int house[], int start, int end) {
    if (start > end) return;
    
    int mid = (start + end) / 2;
    
    if (possible(house, mid)) {
        if (answer < mid) answer = mid;
        bin_search(house, mid + 1, end);
    }
    else {
        bin_search(house, start, mid - 1);
    }
}

int main() {
    cin >> n >> c;
    
    int house[n];
    
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }
    
    sort(house, house + n);
    bin_search(house, 1, house[n - 1] - house[0]);
    cout << answer << '\n';
    
    return 0;
}

#include <iostream>

using namespace std;

int n, m;
long long time_ride = 30;

void bin_search(int rides[], long long start, long long end) {
    if (start > end) return;
    
    long long mid = (start + end) / 2;
    long long cnt = m;
    
    for (int i = 0; i < m; i++) {
        cnt += mid / rides[i];
    }
    
    if (cnt >= n) {
        time_ride = mid;
        bin_search(rides, start, mid - 1);
    }
    else bin_search(rides, mid + 1, end);
}

int main() {
    cin >> n >> m;
    
    int rides[m];
    for (int i = 0; i < m; i++)
        cin >> rides[i];
    
    if (n <= m) {
        cout << n << '\n';
        return 0;
    }
    
    bin_search(rides, 1, 30LL * 2'000'000'000LL);
    
    long long cnt = m;
    for (int i = 0; i < m; i++) {
        cnt += (time_ride - 1) / rides[i];
    }
    
    for (int i = 0; i < m; i++) {
        if (time_ride % rides[i] == 0) ++cnt;
        
        if (cnt == n) {
            cout << i + 1 << '\n';
            break;
        }
    }
    
    return 0;
}

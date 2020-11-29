#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    int cards[n];
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    
    sort(cards, cards + n);
    cin >> m;
    
    int cnt[m];
    for (int i = 0; i < m; i++) {
        cin >> cnt[i];
    }
    
    for (int i = 0; i < m; i++) {
        cout << upper_bound(cards, cards + n, cnt[i]) - lower_bound(cards, cards + n, cnt[i]) << ' ';
    }
    
    return 0;
}

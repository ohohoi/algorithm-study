#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    const int MAX = 10;
    int n, k; //동전의 개수, 만들 가치의 합
    int coin_values[MAX];
    int count = 0;
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> coin_values[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (coin_values[i] <= k) {
            count += k / coin_values[i];
            k %= coin_values[i];
        }
    }
    
    cout << count << '\n';
    
    return 0;
}

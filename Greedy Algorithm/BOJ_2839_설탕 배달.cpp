#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n; // weight of sugar
    int ans = 0; // number of bags
    
    cin >> n;
    
    while (n > 0) {
        if (n % 5 == 0) {
            ans += n / 5;
            break;
        }
        else {
            n -= 3;
            ++ans;
        }
        
        if (n < 0) {
            ans = -1;
            break;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}

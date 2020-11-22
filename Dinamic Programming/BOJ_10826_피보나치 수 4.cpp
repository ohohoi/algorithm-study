#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

string add_str(string a, string b) {
    int a_len = a.length();
    int b_len = b.length();
    int r_len = max(a_len, b_len);
    string result(r_len, '0');
    int tmp = 0;
    
    for (int i = 0; i < r_len; i++) {
        if (i < a_len) tmp += a[a_len - 1 - i] - '0';
        if (i < b_len) tmp += b[b_len - 1 - i] - '0';
        
        if (tmp >= 10) {
            result[r_len - 1 - i] = tmp - 10 + '0';
            tmp = 1;
        }
        else {
            result[r_len - 1 - i] = tmp + '0';
            tmp = 0;
        }
    }
    
    if (tmp == 1) result.insert(result.begin(), '1');
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    if (n == 0 || n == 1) {
        cout << n << '\n';
        return 0;
    }
    
    string fib[n + 1];
    
    fib[0] = "0";
    fib[1] = "1";
    
    for (int i = 2; i <= n; i++) {
        fib[i] = add_str(fib[i - 1], fib[i - 2]);
    }
    
    cout << fib[n] << '\n';
    return 0;
}

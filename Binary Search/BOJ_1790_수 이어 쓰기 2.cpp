#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int n, k;
int m = 1;
long long len_m = 1;

int cnt_digit(int n) {
    int digits = 1;
    while (n /= 10) digits++;
    return digits;
}

long long cnt_length(int n) {
    int digits = cnt_digit(n);
    int length = digits * (n + 1 - pow(10, digits - 1));
    
    for (int i = digits - 1; i > 0; i--)
        length += i * (9 * pow(10, i - 1));
    
    return length;
}

void bin_search(int start, int end) {
    if (start > end) return;
    
    int mid = (start + end) / 2;
    long long len = cnt_length(mid);
    
    if (len == k) {
        m = mid;
        len_m = len;
    }
    else if (len < k) {
        if (m < mid) {
            m = mid;
            len_m = len;
        }
        bin_search(mid + 1, end);
    }
    else {
        bin_search(start, mid - 1);
    }
}

int main() {
    cin >> n >> k;
    
    if (cnt_length(n) < k) {
        cout << "-1\n";
        return 0;
    }
    
    bin_search(1, n);
    
    if (len_m == k) {
        cout << m % 10 << '\n';
    }
    else {
        string str = to_string(m + 1);
        cout << str[k - len_m - 1] << '\n';
    }
    
    return 0;
}

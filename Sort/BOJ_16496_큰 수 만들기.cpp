#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool priority(string a, string b) {
    if (a == b) return false;
    
    string ab = a + b;
    string ba = b + a;
    
    return ab > ba;
}

int main() {
    int n;
    cin >> n;
    
    string numbers[n];
    bool all_zero = true;
    
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (all_zero && numbers[i] != "0") all_zero = false;
    }
    
    if (all_zero) {
        cout << "0\n";
        return 0;
    }
    
    sort(numbers, numbers + n, priority);
    
    for (int i = 0; i < n; i++) {
        cout << numbers[i];
    }
    
    return 0;
}

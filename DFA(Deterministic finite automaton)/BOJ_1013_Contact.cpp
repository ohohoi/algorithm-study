#include <iostream>
#include <string>

using namespace std;

int dfa[10][2] = {
    {8, 1},
    {2, 9},
    {3, 9},
    {3 ,4},
    {8, 5},
    {6, 5},
    {3, 7},
    {8, 1},
    {9, 7},
    {9, 9}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string input;
        cin >> input;
        
        int len = input.length();
        int state = 0;
        
        for (int i = 0; i < len; i++) {
            int signal = input[i] - '0';
            state = dfa[state][signal];
        }
        
        if (state == 4 || state == 5 || state == 7) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

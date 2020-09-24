#include <iostream>
#include <string>

using namespace std;

int state_table[10][2] = {
    {8, 1},
    {2, 9},
    {3, 9},
    {3, 4},
    {8, 5},
    {6, 5},
    {3, 7},
    {8, 1},
    {9, 7},
    {9, 9}
};

int main() {
    string input;
    cin >> input;
    
    int state = 0;
    int len = input.length();
    
    for (int i = 0; i < len; i++) {
        int sound = input[i] - '0';
        state = state_table[state][sound];
    }
    
    if (state == 4 || state == 5 || state == 7) cout << "SUBMARINE\n";
    else cout << "NOISE\n";
    
    return 0;
}

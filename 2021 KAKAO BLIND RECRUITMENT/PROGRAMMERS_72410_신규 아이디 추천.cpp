#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // step 1
    for (int i = 0; i < new_id.length(); i++) {
        char c = new_id[i];
        
        new_id[i] = tolower(c);
    }
    
    // step 2
    for (int i = 0; i < new_id.length(); i++) {
        char c = new_id[i];
        
        if ((c < 'a' || c > 'z') && (c < '0' || c > '9')
                && (c != '.' && c != '-' && c != '_')) {
            new_id.erase(i, 1);
            --i;
        }
    }
    
    // step 3
    bool prev_is_dot = false;

    for (int i = 0; i < new_id.length(); i++) {
        char c = new_id[i];

        if (c != '.') {
            prev_is_dot = false;
            continue;
        }

        if (prev_is_dot) {
            new_id.erase(i, 1);
            --i;
        }
        else {
            prev_is_dot = true;
        }
    }
    
    // step 4
    if (new_id.length() && new_id[0] == '.') {
        new_id.erase(0, 1);
    }
    
    if (new_id.length() && new_id[new_id.length() - 1] == '.') {
        new_id.erase(new_id.length() - 1, 1);
    }
    
    // step 5
    if (!new_id.length()) {
        new_id = "a";
    }
    
    // step 6
    if (new_id.length() > 15) {
        new_id = new_id.substr(0, 15);
    }
    
    if (new_id.length() && new_id[new_id.length() - 1] == '.') {
        new_id.erase(new_id.length() - 1, 1);
    }
    
    // step 7
    while (new_id.length() < 3) {
        new_id.push_back(new_id[new_id.length() - 1]);
    }
    
    answer = new_id;
    
    return answer;
}

int main() {
    string input;
    
    cin >> input;
    solution(input);
    
    return 0;
}

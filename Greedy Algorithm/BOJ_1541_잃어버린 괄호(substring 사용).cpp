#include <iostream>
#include <string>

using namespace std;

string expression;
int subsum(string substr) {
    int result = 0;
    int begin = 0;
    int end = substr.find('+');
    
    while (end != string::npos) {
        result += stoi(substr.substr(begin, end - begin));
        begin = end + 1;
        end = substr.find('+', begin);
    }
    
    result += stoi(substr.substr(begin, end));
    return result;
}

int main() {
    cin >> expression;
    
    int begin = 0;
    int end = expression.find('-');
    
    if (end == string::npos) {
        cout << subsum(expression) << '\n';
        return 0;
    }
    
    int result = subsum(expression.substr(begin, end - begin));
    
    begin = end + 1;
    end = expression.find('-', begin);
    
    while (end != string::npos) {
        result -= subsum(expression.substr(begin, end - begin));
        begin = end + 1;
        end = expression.find('-', begin);
    }
    
    result -= subsum(expression.substr(begin, expression.size() - begin));
    
    cout << result << '\n';
    return 0;
}

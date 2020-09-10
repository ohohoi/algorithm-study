#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string expression;
    stack<int> operands;
    stack<char> operators;
    vector<int> operands_minus;
    
    cin >> expression;
    
    for (int i = 0; i < expression.size(); ) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            int operand = 0;
            while (expression[i] >= '0' && expression[i] <= '9') {
                operand *= 10;
                operand += expression[i] - '0';
                ++i;
            }
            operands.push(operand);
        }
        else {
            operators.push(expression[i]);
            ++i;
        }
    }
    
    while (!operators.empty()) {
        if (operators.top() == '+') {
            int tmp = operands.top();
            operands.pop();
            tmp += operands.top();
            operands.pop();
            operands.push(tmp);
        }
        else {
            operands_minus.push_back(operands.top());
            operands.pop();
        }
        operators.pop();
    }
    
    if (!operands.empty()) operands_minus.push_back(operands.top());
    
    int result = operands_minus[operands_minus.size() - 1];
    for (int i = operands_minus.size() - 2; i >= 0; i--) {
        result -= operands_minus[i];
    }
    
    cout << result << '\n';
    return 0;
}

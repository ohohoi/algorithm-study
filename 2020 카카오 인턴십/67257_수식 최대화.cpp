#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    bool plus_is_included = false;
    bool minus_is_included = false;
    bool multiply_is_included = false;
    vector<char> operator_priority;
    vector<char> operators;
    vector<long long> operands;
    int tmp_operand = 0;
    
    for (int i = 0; i < expression.size(); i++) {
        char curr_char = expression.at(i);
        
        if (curr_char >= '0' && curr_char <= '9') {
            tmp_operand *= 10;
            tmp_operand += curr_char - '0';
        }
        else {
            operands.push_back(tmp_operand);
            tmp_operand = 0;
            
            operators.push_back(curr_char);
            if (curr_char == '+' && plus_is_included == false) {
                operator_priority.push_back('+');
                plus_is_included = true;
            }
            else if (curr_char == '-' && minus_is_included == false) {
                operator_priority.push_back('-');
                minus_is_included = true;
            }
            else if (curr_char == '*' && multiply_is_included == false) {
                operator_priority.push_back('*');
                multiply_is_included = true;
            }
            
        }
    }
    
    operands.push_back(tmp_operand);
    sort(operator_priority.begin(), operator_priority.end());
    
    do {
        vector<char> tmp_operators = operators;
        vector<long long> tmp_operands = operands;
        
        for (int i = 0; i < operator_priority.size(); i++) {
            char to_calculate = operator_priority[i];
            for (int j = 0; j < tmp_operators.size(); j++) {
                if (tmp_operators[j] == to_calculate) {
                    tmp_operators.erase(tmp_operators.begin() + j);
                    if (to_calculate == '+') {
                        tmp_operands[j] += tmp_operands[j + 1];
                        tmp_operands.erase(tmp_operands.begin() + j + 1);
                    }
                    else if (to_calculate == '-') {
                        tmp_operands[j] -= tmp_operands[j + 1];
                        tmp_operands.erase(tmp_operands.begin() + j + 1);
                    }
                    else {
                        tmp_operands[j] *= tmp_operands[j + 1];
                        tmp_operands.erase(tmp_operands.begin() + j + 1);
                    }
                    j--;
                }
            }
        }
        
        long long calc_result = tmp_operands[0];
        
        if (calc_result < 0) {
            calc_result = -calc_result;
        }
        if (calc_result > answer) {
            answer = calc_result;
        }
        
    }while (next_permutation(operator_priority.begin(), operator_priority.end()));
    
    return answer;
}

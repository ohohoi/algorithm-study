#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 1000;
    int len = s.length();
    
    if (len == 1) {
        return 1;
    }
    
    for (int unit = 1; unit <= len / 2; unit++) {
        stack<string> stack_str;
        stack<int> stack_count;
        
        for (int i = 0; i < len; i += unit) {
            string str = s.substr(i, unit);
            if (stack_str.empty()) {
                stack_str.push(str);
                stack_count.push(1);
            }
            else {
                string top = stack_str.top();
                //cout << top << ' ' << str << '\n';
                if (top.compare(str) == 0) {
                    int count = stack_count.top();
                    stack_count.pop();
                    stack_count.push(count + 1);
                }
                else {
                    stack_str.push(str);
                    stack_count.push(1);
                }
            }
        }
        
        int stackSize = stack_count.size();
        int compressionLen = 0;
        
        for (int i = 0; i < stackSize; i++) {
            string top = stack_str.top();
            stack_str.pop();
            compressionLen += top.length();
            
            int count = stack_count.top();
            stack_count.pop();
            
            int chippers = 0;
            if (count != 1) {
                while (count != 0){
                        count /= 10;
                    chippers++;
                }
            }
            compressionLen += chippers;
        }
        
        if (compressionLen < answer) {
            answer = compressionLen;
        }
    }
    return answer;
}

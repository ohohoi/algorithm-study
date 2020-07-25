#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stack;
    
    for (int i = 0; i < moves.size(); i++) {
        int position = moves[i] - 1;
        
        for (int j = 0; j < board.size(); j++) {
            int picked = board[j][position];
            if (picked != 0) {
                if (stack.size() > 0 && stack.top() == picked) {
                    stack.pop();
                    answer += 2;
                }
                else {
                    stack.push(picked);
                }
                board[j][position] = 0;
                break;
            }
        }
    }
    return answer;
}

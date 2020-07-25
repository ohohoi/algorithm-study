#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    if (moves.size() == 1) {
        return answer;
    }
    
    int size = board.size();
    queue<int> queues[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value = board[i][j];
            if (value != 0) {
                queues[j].push(value);
            }
        }
    }
    
    stack<int> basket;
    
    for (int i = 0; i < moves.size(); i++) {
        int position = moves[i] - 1;
        if (queues[position].size() > 0) {
            int picked = queues[position].front();
            queues[position].pop();
            int top = 0;
            if (basket.size() > 0) {
                top = basket.top();
            }
            if (top == picked) {
                basket.pop();
                answer += 2;
            }
            else {
                basket.push(picked);
            }
        }
    }
    return answer;
}

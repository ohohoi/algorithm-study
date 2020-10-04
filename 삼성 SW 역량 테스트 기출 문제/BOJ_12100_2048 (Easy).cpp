#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX = 20;
const int MOVE_MAX = 5;
int n;
int max_value;

vector<vector<int>> up(vector<vector<int>> board);
vector<vector<int>> down(vector<vector<int>> board);
vector<vector<int>> left(vector<vector<int>> board);
vector<vector<int>> right(vector<vector<int>> board);
void slide(vector<vector<int>> board, int move_cnt);

int main() {
    scanf("%d", &n);
    
    vector<vector<int>> board(n);
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int input;
            scanf("%d", &input);
            board[r].push_back(input);
        }
    }
    
    slide(board, 0);
    printf("%d\n", max_value);
    
    return 0;
}

void slide(vector<vector<int>> board, int move_cnt) {
    if (move_cnt == 5) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] > max_value) max_value = board[r][c];
            }
        }
        return;
    }
    
    vector<vector<int>> board_next;
    
    board_next = up(board);
    slide(board_next, move_cnt + 1);

    board_next = down(board);
    slide(board_next, move_cnt + 1);

    board_next = left(board);
    slide(board_next, move_cnt + 1);

    board_next = right(board);
    slide(board_next, move_cnt + 1);
}

vector<vector<int>> up(vector<vector<int>> board) {
    for (int c = 0; c < n; c++) {
        deque<int> deq;
        int combined_top = -1;
        
        for (int r = 0; r < n; r++) {
            if (board[r][c]) {
                if (!deq.empty() && deq.back() == board[r][c] && combined_top != deq.size()) {
                    deq.pop_back();
                    deq.push_back(board[r][c] << 1);
                    combined_top = deq.size();
                }
                else
                    deq.push_back(board[r][c]);
            }
            board[r][c] = 0;
        }
        
        int deq_size = deq.size();
        for (int r = 0; r < deq_size; r++) {
            board[r][c] = deq.front();
            deq.pop_front();
        }
    }
    return board;
}

vector<vector<int>> down(vector<vector<int>> board) {
    for (int c = 0; c < n; c++) {
        deque<int> deq;
        int combined_top = -1;
        
        for (int r = n - 1; r >= 0; r--) {
            if (board[r][c]) {
                if (!deq.empty() && deq.back() == board[r][c] && combined_top != deq.size()) {
                    deq.pop_back();
                    deq.push_back(board[r][c] << 1);
                    combined_top = deq.size();
                }
                else
                    deq.push_back(board[r][c]);
            }
            board[r][c] = 0;
        }
        
        int deq_size = deq.size();
        for (int r = 0; r < deq_size; r++) {
            board[n - 1 - r][c] = deq.front();
            deq.pop_front();
        }
    }
    return board;
}

vector<vector<int>> left(vector<vector<int>> board) {
    for (int r = 0; r < n; r++) {
        deque<int> deq;
        int combined_top = -1;
        
        for (int c = 0; c < n; c++) {
            if (board[r][c]) {
                if (!deq.empty() && deq.back() == board[r][c] && combined_top != deq.size()) {
                    deq.pop_back();
                    deq.push_back(board[r][c] << 1);
                    combined_top = deq.size();
                }
                else
                    deq.push_back(board[r][c]);
            }
            board[r][c] = 0;
        }
        
        int deq_size = deq.size();
        for (int c = 0; c < deq_size; c++) {
            board[r][c] = deq.front();
            deq.pop_front();
        }
    }
    return board;
}

vector<vector<int>> right(vector<vector<int>> board) {
    for (int r = 0; r < n; r++) {
        deque<int> deq;
        int combined_top = -1;
        
        for (int c = n - 1; c >= 0; c--) {
            if (board[r][c]) {
                if (!deq.empty() && deq.back() == board[r][c] && combined_top != deq.size()) {
                    deq.pop_back();
                    deq.push_back(board[r][c] << 1);
                    combined_top = deq.size();
                }
                else
                    deq.push_back(board[r][c]);
            }
            board[r][c] = 0;
        }
        
        int deq_size = deq.size();
        for (int c = 0; c < deq_size; c++) {
            board[r][n - 1 - c] = deq.front();
            deq.pop_front();
        }
    }
    return board;
}

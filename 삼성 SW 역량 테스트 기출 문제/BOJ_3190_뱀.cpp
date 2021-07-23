#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 100;
const int APP = 1;
const int BODY = 2;
const int EMPTY = 0;

int rDir[] = {-1, 0, 1, 0}; // up, right, down left
int cDir[] = {0, 1, 0, -1};

int board[MAX][MAX];
int sec[MAX];
char dir[MAX];

int main() {
    int n;
    int cntApp;
    
    cin >> n >> cntApp;
    
    for (int i = 0; i < cntApp; i++) {
        int r;
        int c;
        
        cin >> r >> c;
        
        board[r - 1][c - 1] = APP;
    }
    
    int cntTurn;
    
    cin >> cntTurn;
    
    for (int i = 0; i < cntTurn; i++) {
        cin >> sec[i] >> dir[i];
    }
    
    int cntSec = 0;
    int currDir = 1; // right
    int currR = 0;
    int currC = 0;
    queue<pair<int, int>> body;
    
    board[0][0] = BODY;
    body.push(pair<int, int>(0, 0));
    
    for (int i = 0; i < cntTurn; i++) {
        int interval = sec[i] - cntSec;
        
        for (int si = 0; si < interval; si++) {
            cntSec++; // 1초 증가
            
            currR += rDir[currDir]; // 이동
            currC += cDir[currDir];
            
            if (currR < 0 || currR >= n || currC < 0 || currC >= n) { // 벽에 닿은 경우
                cout << cntSec << '\n';
                
                return 0;
            }
            
            if (board[currR][currC] == BODY) {  // 몸에 닿은 경우
                cout << cntSec << '\n';
                
                return 0;
            }
            
            if (board[currR][currC] == EMPTY) { // 빈 칸으로 이동한 경우 꼬리 없ㅇ
                int tr = body.front().first;
                int tc = body.front().second;
                
                body.pop();
                board[tr][tc] = EMPTY;
            }
            
            board[currR][currC] = BODY;
            body.push(pair<int, int>(currR, currC));
        }
        
        if (dir[i] == 'L') {
            currDir--;
            if (currDir == -1) {
                currDir = 3;
            }
        }
        else if (dir[i] == 'D') {
            currDir++;
            if (currDir == 4) {
                currDir = 0;
            }
        }
    }
    
    while (true) {
        cntSec++; // 1초 증가
        
        currR += rDir[currDir]; // 이동
        currC += cDir[currDir];
        
        if (currR < 0 || currR >= n || currC < 0 || currC >= n) { // 벽에 닿은 경우
            cout << cntSec << '\n';
            
            return 0;
        }
        
        if (board[currR][currC] == BODY) {  // 몸에 닿은 경우
            cout << cntSec << '\n';
            
            return 0;
        }
        
        if (board[currR][currC] == EMPTY) { // 빈 칸으로 이동한 경우 꼬리 없ㅇ
            int tr = body.front().first;
            int tc = body.front().second;
            
            body.pop();
            board[tr][tc] = EMPTY;
        }
        
        board[currR][currC] = BODY;
        body.push(pair<int, int>(currR, currC));
    }
        
    
    return 0;
}

#include <iostream>

using namespace std;

const int EAST = 1;
const int WEST = 2;
const int NORTH = 3;
const int SOUTH = 4;
const int MAX = 20;

int map[MAX][MAX];
int rDir[] = {0, 0, 0, -1, 1};  // dummy, east, west, north, south
int cDir[] = {0, 1, -1, 0, 0};
int dice[7] = { 0 };

int main() {
    int r, c;
    int sr, sc;
    int cntCmd;
    
    cin >> r >> c >> sr >> sc >> cntCmd;
    
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            cin >> map[ri][ci];
        }
    }
    
    int cmd[cntCmd];
    
    for (int i = 0; i < cntCmd; i++) {
        cin >> cmd[i];
    }
    
    int currR = sr, currC = sc;
    
    for (int i = 0; i < cntCmd; i++) {
        int nr = currR + rDir[cmd[i]], nc = currC + cDir[cmd[i]];
        
        if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
            continue;
        }
        
        int tmp1 = dice[1], tmp2 = dice[2], tmp3 = dice[3],
            tmp4 = dice[4], tmp5 = dice[5], tmp6 = dice[6];
        
        switch (cmd[i]) {
            case EAST:
                dice[1] = tmp3;
                dice[3] = tmp6;
                dice[6] = tmp4;
                dice[4] = tmp1;
                break;
                
            case WEST:
                dice[1] = tmp4;
                dice[4] = tmp6;
                dice[6] = tmp3;
                dice[3] = tmp1;
                break;
                
            case NORTH:
                dice[1] = tmp2;
                dice[2] = tmp6;
                dice[6] = tmp5;
                dice[5] = tmp1;
                break;
                
            case SOUTH:
                dice[1] = tmp5;
                dice[5] = tmp6;
                dice[6] = tmp2;
                dice[2] = tmp1;
                break;
        }
        
        if (map[nr][nc] == 0) {
            map[nr][nc] = dice[1];
        }
        else {
            dice[1] = map[nr][nc];
            map[nr][nc] = 0;
        }
        
        cout << dice[6] << '\n';
        
        currR = nr;
        currC = nc;
    }
    
    return 0;
}

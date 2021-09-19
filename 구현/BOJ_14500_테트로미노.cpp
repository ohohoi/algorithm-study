#include <iostream>
#include <vector>

using namespace std;

const int CNT_TET = 19;
const int R = 0, C = 1;

vector<int> tet[CNT_TET][2] { // r, c 좌표값
    {{0, 1, 1}, {1, 0, 1}},
    {{0, 0, 0}, {1, 2, 3}},
    {{1, 2, 3}, {0, 0, 0}},
    {{1, 2, 2}, {0, 0, 1}},
    {{1, 2, 2}, {0, 0, -1}},
    {{0, 1, 2}, {1, 0, 0}},
    {{0, 1, 2}, {1, 1, 1}},
    {{1, 1, 1}, {0, 1, 2}},
    {{0, 0, 1}, {1, 2, 0}},
    {{0, 0, 1}, {1, 2, 2}},
    {{1, 1, 1}, {-2, -1, 0}},
    {{1, 1, 2}, {0, 1, 1}},
    {{1, 1, 2}, {-1, 0, -1}},
    {{0, 1, 1}, {1, 1, 2}},
    {{0, 1, 1}, {1, -1, 0}},
    {{1, 1, 1}, {-1, 0, 1}},
    {{0, 0, 1}, {1, 2, 1}},
    {{1, 1, 2}, {0, 1, 0}},
    {{1, 1, 2}, {-1, 0, 0}},
};

int main() {
    int r, c;
    
    cin >> r >> c;
    
    int paper[r][c];
    
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            cin >> paper[ri][ci];
        }
    }
    
    int max_sum = 0;
    
    for(int ti = 0; ti < CNT_TET; ti++) {
        
        for (int ri = 0; ri < r; ri++) {
            for (int ci = 0; ci < c; ci++) {
                
                int sum = paper[ri][ci];
                bool fit = true;
                
                for (int i = 0; i < 3; i++) {
                    int nr = ri + tet[ti][R][i], nc = ci + tet[ti][C][i];
                    
                    if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                        fit = false;
                        break;
                    }
                    
                    sum += paper[nr][nc];
                }
                
                if (!fit) continue;
                
                if (sum > max_sum) max_sum = sum;
            }
        }
    }
    
    cout << max_sum << '\n';
    
    return 0;
}

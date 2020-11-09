#include <iostream>
#include <cstring>

using namespace std;

int dir_r[4] = {-1, 0, 1, 0};
int dir_c[4] = {0, 1, 0, -1};

int main() {
    int r, c, t;
    scanf("%d %d %d", &r, &c, &t);
    
    int house[r][c];
    int machine = 0;
    
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            scanf("%d", &house[ri][ci]);
            if (ci == 0 && house[ri][ci] == -1) machine = ri - 1;
        }
    }
    
    while (t--) {
        int tmp[r][c];
        memset(tmp, 0, sizeof(tmp));
        
        for (int ri = 0; ri < r; ri++) {
            for (int ci = 0; ci < c; ci++) {
                int curr = house[ri][ci];
                
                if (curr > 0) {
                    int spread = curr / 5;
                    int cnt_spread = 0;
                    
                    for (int i = 0; i < 4; i++) {
                        int nr = ri + dir_r[i];
                        int nc = ci + dir_c[i];
                        
                        if (nr >= 0 && nr < r && nc >= 0 && nc < c && house[nr][nc] != -1) {
                            cnt_spread++;
                            tmp[nr][nc] += spread;
                        }
                    }
                    
                    tmp[ri][ci] += curr - spread * cnt_spread;
                }
            }
        }
        
        tmp[machine][0] = tmp[machine + 1][0] = 0;
        
        for (int ri = 0; ri < r; ri++) {
            for (int ci = 0; ci < c; ci++) {
                house[ri][ci] = tmp[ri][ci];
            }
        }
        for (int ri = machine - 1; ri > 0; ri--) {
            tmp[ri][0] = tmp[ri - 1][0];
        }
        for (int ci = 0; ci < c - 1; ci++) {
            tmp[0][ci] = tmp[0][ci + 1];
        }
        for (int ri = 0; ri < machine; ri++) {
            tmp[ri][c - 1] = tmp[ri + 1][c - 1];
        }
        for (int ci = c - 1; ci > 1; ci--) {
            tmp[machine][ci] = tmp[machine][ci - 1];
        }
        tmp[machine][1] = 0;
        
        for (int ri = machine + 2; ri < r - 1; ri++) {
            tmp[ri][0] = tmp[ri + 1][0];
        }
        for (int ci = 0; ci < c - 1; ci++) {
            tmp[r - 1][ci] = tmp[r - 1][ci + 1];
        }
        for (int ri = r - 1; ri > machine + 1; ri--) {
            tmp[ri][c - 1] = tmp[ri - 1][c - 1];
        }
        for (int ci = c - 1; ci > 1; ci--) {
            tmp[machine + 1][ci] = tmp[machine + 1][ci - 1];
        }
        tmp[machine + 1][1] = 0;
        
        for (int ri = 0; ri < r; ri++) {
            for (int ci = 0; ci < c; ci++) {
                house[ri][ci] = tmp[ri][ci];
            }
        }
    }
    
    int answer = 0;
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            answer += house[ri][ci];
        }
    }
    
    printf("%d\n", answer);
    return 0;
}

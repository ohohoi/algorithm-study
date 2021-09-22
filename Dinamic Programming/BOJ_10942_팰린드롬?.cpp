#include <iostream>

using namespace std;

const int MAX = 2001;

int num[MAX];
bool d[MAX][MAX];

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    int cnt_num, cnt_que;
    
    cin >> cnt_num;
    
    for (int i = 1; i <= cnt_num; i++) {
        cin >> num[i];
    }
    
    for (int i = 1; i <= cnt_num; i++) {
        d[i][i] = true;
    }
    
    for (int l = cnt_num; l >= 1; l--) {
        for (int r = l + 1; r <= cnt_num; r++) {
            if (num[l] == num[r]) {
                d[l][r] = true;
                
                if (l + 1 <= r - 1 && d[l + 1][r - 1] == false) {
                    d[l][r] = false;
                }
            }
        }
    }
    
    cin >> cnt_que;
    
    for (int i = 0; i < cnt_que; i++) {
        int l, r;
        
        cin >> l >> r;
        cout << d[l][r] << '\n';
    }
    
    return 0;
}

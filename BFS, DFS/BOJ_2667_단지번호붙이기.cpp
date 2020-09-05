#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool house_exists[25][25];
bool visited[25][25];
int x_direction[] = {0, 1, 0, -1};
int y_direction[] = {-1, 0, 1, 0};
int house_count = 0;
vector<int> house_count_vec;

void dfs(int x, int y) {
    visited[x][y] = true;
    ++house_count;
    for (int i = 0; i < 4; i++) {
        int next_x = x + x_direction[i];
        int next_y = y + y_direction[i];
        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
            if(house_exists[next_x][next_y] && !visited[next_x][next_y]) {
                dfs(next_x, next_y);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> complex;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str_tmp;
        cin >> str_tmp;
        for (int j = 0; j < n; j++) {
            house_exists[i][j] = str_tmp[j] - '0';
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(house_exists[i][j] && !visited[i][j]) {
                house_count = 0;
                dfs(i, j);
                house_count_vec.push_back(house_count);
            }
        }
    }
    
    sort(house_count_vec.begin(), house_count_vec.end());
    cout << house_count_vec.size() << '\n';
    for (int i = 0; i < house_count_vec.size(); i++) {
        cout << house_count_vec[i] << '\n';
    }
    
    return 0;
}

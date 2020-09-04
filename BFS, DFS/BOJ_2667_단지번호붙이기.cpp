#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
bool house_exists[25][25];
bool visited[25][25];
int x_direction[] = {0, 1, 0, -1};
int y_direction[] = {-1, 0, 1, 0};
map<int, int> complex_count_map;
vector<int> complex_count_vector;

void dfs(int x, int y, int complex_num) {
    visited[x][y] = true;
    ++complex_count_map[complex_num];
    for (int i = 0; i < 4; i++) {
        int next_x = x + x_direction[i];
        int next_y = y + y_direction[i];
        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
            if(house_exists[next_x][next_y] && !visited[next_x][next_y]) {
                dfs(next_x, next_y, complex_num);
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
    
    int complex_num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(house_exists[i][j] && !visited[i][j]) {
                complex_count_map[complex_num] = 0;
                dfs(i, j, complex_num++);
            }
        }
    }
    
    cout << complex_count_map.size() << '\n';
    for (int i = 1; i <= complex_count_map.size(); i++) {
        complex_count_vector.push_back(complex_count_map[i]);
    }
    sort(complex_count_vector.begin(), complex_count_vector.end());
    for (int i = 0; i < complex_count_vector.size(); i++) {
        cout << complex_count_vector[i] << '\n';
    }
    
    return 0;
}

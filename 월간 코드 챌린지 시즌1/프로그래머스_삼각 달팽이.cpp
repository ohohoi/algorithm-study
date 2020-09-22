#include <iostream>
#include <string>
#include <vector>

using namespace std;

int row = 0, col = 0;
int r_direction[3] = { 1, 0, -1 };
int c_direction[3] = { 0, 1, -1 };

vector<int> solution(int n) {
    int arr[n + 1][n];
    int value = 1;
    for (int i = 0; i < n; i++) {
        int dir = i % 3;
        for (int j = 0; j < n - i; j++) {
            row += r_direction[dir];
            col += c_direction[dir];
            arr[row][col] = value++;
        }
    }
    
    vector<int> answer;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}

int main() {
    vector<int> ans = solution(6);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}

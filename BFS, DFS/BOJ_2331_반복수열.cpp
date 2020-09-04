#include <iostream>

using namespace std;

const int MAX_NUM = 9999 * 5;
int visited[MAX_NUM];

int dfs(int a, int p, int count) {
    if(visited[a] != 0)  return visited[a] - 1;
    visited[a] = count;
    
    int next_num = 0;
    while (a > 0) {
        int num_to_multiply = a % 10;
        int multiples = 1;
        for (int i = 0; i < p; i++) {
            multiples *= num_to_multiply;
        }
        next_num += multiples;
        a /= 10;
    }

    return dfs(next_num, p, ++count);
}

int main(int argc, const char * argv[]) {
    int a, p;
    
    cin >> a >> p;
    cout << dfs(a, p, 1) << '\n';
    
    return 0;
}

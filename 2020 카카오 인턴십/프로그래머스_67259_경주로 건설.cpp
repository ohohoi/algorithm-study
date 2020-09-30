#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

struct Car {
    int r, c, dir, cost;
};

int min_cost = 0x7fffffff;
int dir_r[4] = {-1, 0, 1, 0};
int dir_c[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> board) {
    int n = board.size();
    queue<Car> q;
    q.push({0, 0, 5, 0});
    board[0][0] = 1;

    while(!q.empty()) {
        Car car = q.front();
        q.pop();

        int cost = car.cost;

        if (car.r == n - 1 && car.c == n - 1) {
            if (cost < min_cost) min_cost = cost;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            if (abs(i - car.dir) == 2) continue;

            int next_r = car.r + dir_r[i];
            int next_c = car.c + dir_c[i];

            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n
                && board[next_r][next_c] != 1) {

                int new_cost = cost;
                if (i == car.dir || (car.r == 0 && car.c == 0)) new_cost += 100;
                else new_cost += 600;

                if (board[next_r][next_c] == 0 || board[next_r][next_c] >= new_cost) {
                    q.push({next_r, next_c, i, new_cost});
                    board[next_r][next_c] = new_cost;
                }
            }
        }
    }

    return min_cost;
}

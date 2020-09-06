#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        const int MAX = 10001;
        int a, b;
        bool visited[MAX];
        int from[MAX];
        char command_used[MAX];
        
        cin >> a >> b;
        memset(visited, false, sizeof(visited));
        
        queue<int> q;
        q.push(a);
        visited[a] = true;
        
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            if (n == b) break;
            
            int result_d = n * 2 % 10000;
            int result_s = n - 1;
            if (result_s == -1) result_s = 9999;
            int result_l = n % 1000 * 10 + n / 1000;
            int result_r = n % 10 * 1000 + n / 10;

            if (!visited[result_d]) {
                q.push(result_d);
                visited[result_d] = true;
                from[result_d] = n;
                command_used[result_d] = 'D';
            }
            if (!visited[result_s]) {
                q.push(result_s);
                visited[result_s] = true;
                from[result_s] = n;
                command_used[result_s] = 'S';
            }
            if (!visited[result_l]) {
                q.push(result_l);
                visited[result_l] = true;
                from[result_l] = n;
                command_used[result_l] = 'L';
            }
            if (!visited[result_r]) {
                q.push(result_r);
                visited[result_r] = true;
                from[result_r] = n;
                command_used[result_r] = 'R';
            }
        }
        
        string ans = "";
        int tmp = b;
        while(tmp != a) {
            ans = command_used[tmp] + ans;
            tmp = from[tmp];
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}

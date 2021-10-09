#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;
    
    cin >> a >> b;
    
    queue<pair<long long, int>> q; // pair first: number, second: count;
    
    q.push({a, 0});
    
    while (!q.empty()) {
        long long num = q.front().first;
        int cnt = q.front().second;
        
        q.pop();
        
        if (num == b) {
            cout << cnt + 1 << '\n';
            
            return 0;
        }
        
        if (num > b) continue;
        
        q.push({num * 2, cnt + 1});
        q.push({num * 10 + 1, cnt + 1});
    }
    
    cout << "-1\n";
    
    return 0;
}

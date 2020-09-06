#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    vector<int> p;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        p.push_back(input);
    }
    
    sort(p.begin(), p.end());
    
    int total_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += p[i] * (n - i);
    }
    
    cout << total_time << '\n';
    
    return 0;
}

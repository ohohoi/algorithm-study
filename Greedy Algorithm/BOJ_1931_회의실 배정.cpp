#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool priority(pair<long long, long long> meeting1, pair<long long, long long> meeting2) {
    if (meeting1.second < meeting2.second) return true;
    if (meeting1.second == meeting2.second && meeting1.first < meeting2.first) return true;
    return false;
}

int main() {
    int n;
    vector<pair<long long, long long>> time;
    
    cin >> n;
    
    while (n--) {
        long long start, end;
        cin >> start >> end;
        time.push_back(make_pair(start, end));
    }
    
    sort(time.begin(), time.end(), priority);
    
    int count = 1;
    long long finish_time = time[0].second;
    
    for (int i = 1; i < time.size(); i++) {
        if (time[i].first >= finish_time) {
            ++count;
            finish_time = time[i].second;
        }
    }
    
    cout << count << '\n';
    return 0;
}

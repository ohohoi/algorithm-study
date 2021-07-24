#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int to_sec(string time) {
    return stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
}

string to_str(int sec) {
    string time = "00:00:00";
    int hour = sec / 3600;
    
    time[0] = (char)(hour / 10 + '0');
    time[1] = (char)(hour % 10 + '0');
    sec %= 3600;
    
    int minute = sec / 60;
    
    time[3] = (char)(minute / 10 + '0');
    time[4] = (char)(minute % 10 + '0');
    sec %= 60;
    
    time[6] = (char)(sec / 10 + '0');
    time[7] = (char)(sec % 10 + '0');
    
    return time;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int play_sec = to_sec(play_time);
    int adv_sec = to_sec(adv_time);
    
    if (play_sec == adv_sec) {
        return "00:00:00";
    }
    
    int cnt_log[play_sec];

    memset(cnt_log, 0, sizeof(cnt_log));

    for (int li = 0; li < logs.size(); li++) {
        int start_sec = to_sec(logs[li].substr(0, 8));
        int end_sec = to_sec(logs[li].substr(9, 8));

        for (int si = start_sec; si < end_sec; si++) {
            cnt_log[si]++;
        }
    }
    
    // sliding window
    long long window_sum = 0;
    int start_sec = 0;
    
    for (int i = 0; i < adv_sec; i++) {
        window_sum += cnt_log[i];
    }
    
    long long max_window_sum = window_sum;
    
    for (int s = 0, e = adv_sec; e < play_sec; s++, e++) {
        window_sum += cnt_log[e];
        window_sum -= cnt_log[s];
        
        if (window_sum > max_window_sum) {
            max_window_sum = window_sum;
            start_sec = s + 1;
        }
    }
    
    return to_str(start_sec);
}

int main() {
    string play_time[] = { "02:03:55", "99:59:59", "50:00:00" };
    string adv_time[] = { "00:14:15", "25:00:00", "50:00:00" };
    vector<string> logs[] = {
        { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" },
        { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" },\
        { "15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45" }
    };
    
    for (int i = 0; i < 3; i++) {
        string answer = solution(play_time[i], adv_time[i], logs[i]);
        
        cout << answer << '\n';
    }
    
    return 0;
}

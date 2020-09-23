#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int len = a.size();
    int prefix_min = 0x7fffffff;
    int suffix_min = 0x7fffffff;
    int p_min[len];
    int s_min[len];
    
    for (int i = 0; i < len; i++) {
        if (a[i] < prefix_min) prefix_min = a[i];
        p_min[i] = prefix_min;
    }
    
    for (int i = len - 1; i >= 0; i--) {
        if (a[i] < suffix_min) suffix_min = a[i];
        s_min[i] = suffix_min;
    }
    
    for (int i = 0; i < len; i++) {
        if (a[i] <= p_min[i] || a[i] <= s_min[i]) answer++;
    }
    
    return answer;
}

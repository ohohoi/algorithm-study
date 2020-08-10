#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_mid_is_small(vector<int>stones, int mid, int k) {
    int jump = 1;
    bool small = false;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - mid <= 0) {
            jump++;
        }
        else {
            jump = 1;
        }
        if (jump > k) {
            small = true;
            break;
        }
    }
    return small;
}

int solution(vector<int> stones, int k) {
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());

    while (left <= right) {
        int mid = (left + right) / 2;
        bool small = check_mid_is_small(stones, mid, k);
        if (small) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return left;
}

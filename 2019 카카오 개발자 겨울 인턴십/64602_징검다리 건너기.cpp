#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());

    while (left <= right) {
        int mid = (left + right) / 2;
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
        if (small) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return left;
}

#include <string>
#include <vector>

using namespace std;

int distanceArr[4][12] = {
    {0, 4, 3, 4, 3, 2, 3, 2, 1, 2, 1, 1},
    {3, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 4},
    {2, 2, 1, 2, 1, 0, 1, 2, 1, 2, 3, 3},
    {1, 3, 2, 3, 2, 1, 2, 1, 0, 1, 2, 2}
};

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int rightPosition = 11;
    int leftPosition = 10;
    
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num == 1 || num == 4 || num == 7) {
            answer += 'L';
            leftPosition = num;
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += 'R';
            rightPosition = num;
        }
        else {
            int distanceIndex = (num + 1) / 3;
        
            int leftDistance = distanceArr[distanceIndex][leftPosition];
            int rightDistance = distanceArr[distanceIndex][rightPosition];
            
            if (leftDistance == rightDistance && hand.at(0) == 'l') {
                answer += 'L';
                leftPosition = num;
            }
            else if (leftDistance < rightDistance) {
                answer += 'L';
                leftPosition = num;
            }
            else {
                answer += 'R';
                rightPosition = num;
            }
        }
    }
    
    return answer;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int len = numbers.size();
    
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}

int main() {
    int arr[5] = {5,0,2,7};
    vector<int> numbers(arr, arr + 4);
    vector<int> answer = solution(numbers);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}

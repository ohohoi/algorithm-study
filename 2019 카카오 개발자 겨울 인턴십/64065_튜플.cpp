#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<string, int> map;
    int countBracket = 0;
    string key = "";
    
    for (int i = 0; i < s.size(); i++) {
        char symbol = s[i];
        if (symbol >= '0' && symbol <= '9') {
            key = key + symbol;
        }
        else {
            if (key.compare("") != 0) {
                if(map.find(key) == map.end()) {
                    map[key] = 0;
                }
                else {
                    map[key]++;
                }
                key = "";
            }
        }
    }
    
    int mapSize = map.size();

    int answerArr[mapSize];
    
    for (auto it=map.begin(); it!=map.end(); ++it){
        answerArr[mapSize - 1 - it->second] = stoi(it->first);
    }
    
    for (int i = 0; i < mapSize; i++) {
        answer.push_back(answerArr[i]);
    }
    
    return answer;
}

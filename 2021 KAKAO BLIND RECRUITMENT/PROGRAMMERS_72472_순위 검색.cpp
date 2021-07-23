#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_str(string str) {
    vector<string> splited_str;
    string word = "";
    
    for (char c:str) {
        if (c == ' ') {
            if (word != "" && word != "and") {
                splited_str.push_back(word);
            }
            word = "";
        }
        else {
            word += c;
        }
    }
    
    if (word != "" && word != "and") {
        splited_str.push_back(word);
    }
    
    return splited_str;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> store[3][2][2][2];
    
    for (int i = 0; i < info.size(); i++) {
        string str_info = info[i];
        vector<string> splited_str = split_str(str_info);
        int si[4]; // store index
        
        for (int i = 0; i < 4; i++) {
            if (splited_str[i] == "cpp" || splited_str[i] == "backend"
                || splited_str[i] == "junior" || splited_str[i] == "chicken") {
                si[i] = 0;
            }
            else if (splited_str[i] == "java" || splited_str[i] == "frontend"
                     || splited_str[i] == "senior" || splited_str[i] == "pizza") {
                si[i] = 1;
            }
            else {
                si[i] = 2;
            }
        }

        store[si[0]][si[1]][si[2]][si[3]].push_back(stoi(splited_str[4]));
    }
    
    for (int i = 0; i < query.size(); i++) {
        string str_query = query[i];
        vector<string> splited_str = split_str(str_query);
        
        int start[4], end[4];
        int score = stoi(splited_str[4]);
        
        for (int i = 0; i < 4; i++) {
            if (splited_str[i] == "cpp" || splited_str[i] == "backend"
                || splited_str[i] == "junior" || splited_str[i] == "chicken") {
                start[i] = 0;
                end[i] = 1;
            }
            else if (splited_str[i] == "java" || splited_str[i] == "frontend"
                     || splited_str[i] == "senior" || splited_str[i] == "pizza") {
                start[i] = 1;
                end[i] = 2;
            }
            else if (splited_str[i] == "python"){
                start[i] = 2;
                end[i] = 3;
            }
            else {
                start[i] = 0;
                
                if (i == 0) {
                    end[i] = 3;
                }
                else {
                    end[i] = 2;
                }
            }
        }
        
        // search
        int cnt = 0;
        
        for (int i = start[0]; i < end[0]; i++) {
            for (int j = start[1]; j < end[1]; j++) {
                for (int k = start[2]; k < end[2]; k++) {
                    for (int l = start[3]; l < end[3]; l++) {
                        vector<int> scores = store[i][j][k][l];
                        
                        for (int si = 0; si < scores.size(); si++) {
                            if (scores[si] >= score) {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> info = {"java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100",
        "python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250",
        "- and backend and senior and - 150",
        "- and - and - and chicken 100",
        "- and - and - and - 150"};
    
    vector<int> answer = solution(info, query);
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
    
    return 0;
}

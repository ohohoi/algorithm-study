#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool check[10];
set<string> s;

bool mapping(vector<string> &picked_id, vector<string> &banned_id) {
    for (int i = 0; i < picked_id.size(); i++) {
        if (picked_id[i].size() != banned_id[i].size()) {
            return false;
        }

        for (int j = 0; j < picked_id[i].size(); j++) {
            if (banned_id[i].at(j) != '*' && picked_id[i].at(j) != banned_id[i].at(j)) {
                return false;
            }
        }
    }
    return true;
}

int combination(vector<string> &user_id, vector<string> &banned_id, vector<string> picked_id) {
    if (banned_id.size() == picked_id.size()) {
        if (mapping(picked_id, banned_id)) {
            sort(picked_id.begin(), picked_id.end());
            string combined_str = "";
            for (int i = 0; i < picked_id.size(); i++) {
                combined_str += picked_id[i];
            }
            
            if (s.find(combined_str) == s.end()) {
                s.insert(combined_str);
                return 1;
            }
        }
        return 0;
    }
    
    int result = 0;
    
    for (int i = 0; i < user_id.size(); i++) {
        if(!check[i]) {
            check[i] = true;
            picked_id.push_back(user_id[i]);
            
            result += combination(user_id, banned_id, picked_id);
            picked_id.pop_back();
            check[i] = false;
        }
    }
    
    return result;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<string> v;

    answer = combination(user_id, banned_id, v);

    return answer;
}

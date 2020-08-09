#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> cnt_gems;
    
    for (int i = 0; i < gems.size(); i++) {
        cnt_gems.insert(make_pair(gems[i], 0));
    }
    
    int types = cnt_gems.size();
    
    if (types == 1) {
        answer.push_back(1);
        answer.push_back(1);
        return answer;
    }
    
    int begin = 0;
    int end = 0;
    int cnt_shortest = 100000;
    int begin_shortest = 0;
    int end_shortest = 0;
    unordered_set<string> selected_gems;
    
    while(true) {
        if (selected_gems.size() == types) {
            int cnt_selected = end - begin;
            if (cnt_selected < cnt_shortest) {
                cnt_shortest = cnt_selected;
                begin_shortest = begin;
                end_shortest = end;
            }
            if (--cnt_gems[gems[begin]] == 0) {
                selected_gems.erase(gems[begin]);
            }
            begin++;
        }
        else if (end == gems.size()) break;
        else {
            selected_gems.insert(gems[end]);
            cnt_gems[gems[end++]]++;
        }
    }
    
    answer.push_back(begin_shortest + 1);
    answer.push_back(end_shortest);
    return answer;
}

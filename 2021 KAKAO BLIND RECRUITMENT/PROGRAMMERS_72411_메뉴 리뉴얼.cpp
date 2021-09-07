//
//  main.cpp
//  PROGRAMMERS_72411_메뉴 리뉴얼
//
//  Created by 방경림 on 2021/09/07.
//

#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
#include <map>

using namespace std;

map<string, int> orderCnt;
int courseMaxCnt[11];
vector<string> courseMenu[11][21];

void make_comb (string original, int end_idx, string made) {
    int madeLen = made.size();
    
    if (madeLen >= 2) {
        orderCnt[made]++;
        courseMaxCnt[madeLen] = max(courseMaxCnt[madeLen], orderCnt[made]);
        courseMenu[madeLen][orderCnt[made]].push_back(made);
    }
    
    for (int i = end_idx + 1; i < original.size(); i++) {
        string next = made + original[i];
        make_comb(original, i, next);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int oi = 0; oi < orders.size(); oi++) {
        string order = orders[oi];
        
        sort(order.begin(), order.end());
        make_comb(order, -1, "");
    }
    
    
    
    for (int ci = 0; ci < course.size(); ci++) {
        int c = course[ci];
        int maxCnt = courseMaxCnt[c];
        
        if (c < 2) {
            continue;;
        }
        
        if (maxCnt < 2) {
            continue;;
        }
        
        for (int mi = 0; mi < courseMenu[c][maxCnt].size(); mi++) {
            answer.push_back(courseMenu[c][maxCnt][mi]);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    vector<string> orders[3] = {
        {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"},
        {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"},
        {"XYZ", "XWY", "WXA"}
    };
    
    vector<int> course[3] = {
        {2,3,4},
        {2,3,5},
        {2,3,4}
    };
    
    int tc = 2;
    vector<string> answer = solution(orders[tc], course[tc]);
    
    for (int ai = 0; ai < answer.size(); ai++) {
        string menu = answer[ai];
        
        cout << menu << '\n';
    }
    
    return 0;
}

#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    int len = p.length();
    if (len == 0) {
        return "";
    }
    
    int balanced = 0;
    string u = "";
    string v = "";
    bool u_is_correct = true;
    for (int i = 0; i < len; i++) {
        if (p.at(i) == '(') {
            balanced++;
        }
        else {
            balanced--;
            if (balanced < 0) {
                u_is_correct = false;
            }
        }
        
        if (balanced == 0) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1, len - i);
            break;
        }
    }
    
    if (u_is_correct) {
        string res = u + solution(v);
        return res;
    }
    else {
        string convert_v = "(";
        convert_v += solution(v);
        convert_v += ')';
    
        string convert_u = "";
        for (int i = 1; i < u.length() - 1; i++) {
            if (u.at(i) == '(') {
                convert_u += ')';
            }
            else {
                convert_u += '(';
            }
        }
        return convert_v + convert_u;
    }
}

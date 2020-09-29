#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string k, p;
    getline(cin, k);
    getline(cin, p);
    
    int k_len = k.length(), p_len = p.length();
    
    vector<int> fail(p_len);

    for (int i = 1, j = 0; i < p_len; i++) {
        while (j > 0 && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j]) fail[i] = ++j;
    }

    vector<int> ans;
    
    for (int i = 0, j = 0; i < k_len; i++) {
        while (j > 0 && k[i] != p[j]) j = fail[j - 1];
        
        if (k[i] == p[j]) {
            if (j == p_len - 1) {
                ans.push_back(i - p_len + 2);
                j = fail[j];
            }
            else
                j++;
        }
    }
    
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}

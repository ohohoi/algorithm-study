#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int lcs[MAX][MAX];

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    int len1 = str1.length();
    int len2 = str2.length();
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    
    printf("%d\n", lcs[len1][len2]);
    return 0;
}

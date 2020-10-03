#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> lope(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &lope[i]);
    }
    
    sort(lope.begin(), lope.end(), compare);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int weight = lope[i] * (i + 1);
        if (weight > ans) ans = weight;
    }
    
    printf("%d\n", ans);
    return 0;
}

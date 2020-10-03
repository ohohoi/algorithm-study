#include <iostream>

int main() {
    int money;
    scanf("%d", &money);
    money = 1000 - money;
    
    const int UNIT_CNT = 6;
    int unit[UNIT_CNT] = {500, 100, 50, 10, 5, 1};
    
    int cnt = 0;
    for (int i = 0; i < UNIT_CNT; i++) {
        while (money >= unit[i]) {
            money -= unit[i];
            cnt++;
        }
    }
    
    printf("%d\n", cnt);
    return 0;
}

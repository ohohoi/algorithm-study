#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <utility>

using namespace std;

const int HOU = 1, CHI = 2;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    int city[n][n];
    int min_dist[n][n];
    vector<pair<int, int>> chickens;
    int cnt_chicken = 0;
    
    for (int ri = 0; ri < n; ri++) {
        for (int ci = 0; ci < n; ci++) {
            cin >> city[ri][ci];
            
            min_dist[ri][ci] = INT_MAX;
            
            if (city[ri][ci] == CHI) {
                chickens.push_back({ ri, ci });
                cnt_chicken++;
            }
        }
    }
    
    vector<bool> comb(cnt_chicken - m, false);
    
    comb.insert(comb.end(), m, true);
    
    int min_city_dist = INT_MAX;
    
    do {
        for (int ri = 0; ri < n; ri++) {
            for (int ci = 0; ci < n; ci++) {
                min_dist[ri][ci] = INT_MAX;
            }
        }
        
        for (int ci = 0; ci < cnt_chicken; ci++) {
            if (!comb[ci]) continue;
            
            pair<int, int> ch = chickens[ci];
            
            for (int ri = 0; ri < n; ri++) {
                for (int ci = 0; ci < n; ci++) {
                    if (city[ri][ci] != HOU) continue;
                    
                    int d = abs(ch.first - ri) + abs(ch.second - ci);
                    
                    if (d < min_dist[ri][ci]) min_dist[ri][ci] = d;
                }
            }
        }
        
        int dist_sum = 0;
        
        for (int ri = 0; ri < n; ri++) {
            for (int ci = 0; ci < n; ci++) {
                if (city[ri][ci] != HOU) continue;
                
                dist_sum += min_dist[ri][ci];
            }
        }
        
        if (dist_sum < min_city_dist) min_city_dist = dist_sum;
        
    } while(next_permutation(comb.begin(), comb.end()));

    cout << min_city_dist << '\n';
    
    return 0;
}

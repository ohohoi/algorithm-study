#include <string>
#include <vector>
#include <map>

using namespace std;

vector<long long> answer;
map<long long, long long> room_map;

long long find_num(long long room_num) {
    if (room_map.find(room_num) == room_map.end()) {
        return room_num;
    }
    room_map[room_num] = find_num(room_map[room_num]);
    return room_map[room_num];
}

vector<long long> solution(long long k, vector<long long> room_number) {
    for (int i = 0; i < room_number.size(); i++) {
        long long room_num = room_number[i];
        
        if (room_map.find(room_num) == room_map.end()) {
            room_map[room_num] = room_num + 1;
            answer.push_back(room_num);
        }
        else {
             long long available_num = find_num(room_num);
             answer.push_back(available_num);
             room_map[available_num] =  find_num(available_num + 1);
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> order;
    for(int i=0; i<dungeons.size(); i++) {
        order.push_back(i);
    }
    do {
        int stamina = k;
        int stage = 0;
        for(int i : order) {
            if(stamina >= dungeons[i][0]) {
                stage += 1;
                stamina -= dungeons[i][1];
            } else {
                answer = max(answer, stage);
                break;
            }
        }
        answer = max(answer, stage);
    } while(next_permutation(order.begin(), order.end()));
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int first = 0;
    int second = 0;
    int third = 0;
    vector<vector<int>> v {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };
    for(int i=0; i<answers.size(); i++) {
        if(v[0][i%v[0].size()] == answers[i]) {
            first += 1;
        }
        if(v[1][i%v[1].size()] == answers[i]) {
            second += 1;
        }
        if(v[2][i%v[2].size()] == answers[i]) {
            third += 1;
        }
    }
    int maxN = max({first,second,third});
    if(first == maxN) answer.push_back(1);
    if(second == maxN) answer.push_back(2);
    if(third == maxN) answer.push_back(3);
    return answer;
}
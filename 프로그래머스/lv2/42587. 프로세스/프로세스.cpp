#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> v(10,0);
    queue<int> q;
    
    int firstMaxIdx = 0;
    int firstMax = 0;
    for(int i=0; i<priorities.size(); i++) {
        if(priorities[i] > firstMax) {
            firstMaxIdx = i;
            firstMax = priorities[i];
        }
        v[priorities[i]] += 1;
    }
    
    int cnt = 0;
    for(int i=0;;i++) {
        if(v[firstMax] == 0) {
            firstMax -= 1;
            i -= 1;
            continue;
        }
        
        int idx = (firstMaxIdx+i)%priorities.size();
        
        if(priorities[idx] == firstMax) {
            cnt += 1;
            v[firstMax] -= 1;
        }
        if(idx == location && firstMax == priorities[location]) {
            answer = cnt;
            break;
        }
    }
    
    return answer;
}
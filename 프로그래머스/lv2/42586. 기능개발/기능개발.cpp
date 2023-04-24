#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i=0; i<progresses.size(); i++) {
        int N = 100 - progresses[i];
        if(N%speeds[i] != 0) {
            N = (N / speeds[i]) + 1;
        } else {
            N /= speeds[i];
        }
        q.push(N);
    }
    
    int cnt = 0;
    int prevN = -1;
    
    while(!q.empty()) {
        int n = q.front();
        if(prevN < n) {
            if(prevN == -1) {
                cnt += 1;
            } else {
                answer.push_back(cnt);
                cnt = 1;
            }
            prevN = n;
        } else {
            cnt += 1;
        }
        if(q.size() == 1) {
            answer.push_back(cnt);
        }
        q.pop();
    }
    return answer;
}
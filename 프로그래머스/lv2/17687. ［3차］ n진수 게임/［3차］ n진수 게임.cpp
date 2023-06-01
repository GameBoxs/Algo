#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

deque<char> Dec(int currentN) {
    deque<char> q;
    string convert = to_string(currentN);
    for(int i=0; i<convert.size(); i++) {
        q.push_back(convert[i]);
    }
    return q;
}

deque<char> Other(int target, int currentN) {
    char charArr[] = {'A','B','C','D','E','F'};
    deque<char> q;
    if(target < 10) {
        while(currentN > target-1) {
            q.push_front((currentN % target)+'0');
            currentN /= target;
        }
        q.push_front(currentN + '0');
    } else {
        while(currentN > target-1) {
            int temp = currentN % target;
            if(temp >= 10) {
                q.push_front(charArr[temp-10]);
            } else {
                q.push_front(temp + '0');
            }
            currentN /= target;
        }
        if(currentN >= 10) {
            q.push_front(charArr[currentN-10]);
        } else {
            q.push_front(currentN + '0');
        }
    }
    return q;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int currentTurn = 1;
    int currentNum = 0;
    while(answer.size() != t) {
        deque<char> q = n == 10 ? Dec(currentNum) : Other(n, currentNum);
        while(!q.empty()) {
            if(currentTurn == p) {
                answer += q.front();
            }
            q.pop_front();
            currentTurn = currentTurn + 1 > m ? 1 : currentTurn + 1;
            if(answer.size() == t) return answer;
        }
        currentNum += 1;
    }
    return answer;
}
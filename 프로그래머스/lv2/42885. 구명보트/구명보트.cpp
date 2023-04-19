#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int leftPoint = 0;
    int rightPoint = people.size()-1;
    int currentCnt = 0;
    sort(people.begin(), people.end());
    
    while(currentCnt != people.size()) {
        if(leftPoint == rightPoint) {
            answer +=1;
            break;
        }
        if(people[leftPoint] + people[rightPoint] > limit) {
            currentCnt += 1;
            rightPoint -= 1;
        } else if(people[leftPoint] + people[rightPoint] <= limit) {
            currentCnt += 2;
            leftPoint += 1;
            rightPoint -= 1;
        }
        if(rightPoint < 0) rightPoint = 0;
        if(leftPoint > people.size()-1) leftPoint = people.size()-1;
        answer += 1;
    } 
    
    return answer;
}
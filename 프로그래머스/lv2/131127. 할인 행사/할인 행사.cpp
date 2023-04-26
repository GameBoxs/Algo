#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool check(vector<string> want, map<string, int> mapA, map<string, int> mapB) {
    for(int i=0; i<want.size(); i++) {
        string str = want[i];
        if(mapA[str] > mapB[str]) {
            return false;
        }
   }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> wantMap;
    map<string, int> countMap;
    
    for(int i=0; i<want.size(); i++) {
        wantMap.insert({want[i],number[i]});
    }
    
    for(int i=0; i<10; i++) {
       countMap[discount[i]] += 1;
    }
    for(int i=0; i<=discount.size()-10; i++) {
        if(check(want, wantMap, countMap)) {
            answer += 1;
        }
        if(i == discount.size()-10) {
            break;
        }
        countMap[discount[i]] -= 1;
        countMap[discount[i+10]] += 1;
    }
    
    return answer;
}
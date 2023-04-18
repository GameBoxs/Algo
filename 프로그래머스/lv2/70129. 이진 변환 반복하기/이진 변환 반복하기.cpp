#include <string>
#include <vector>
#include <iostream>

using namespace std;

string convertToTwo(int n) {
    string result="";
    vector<int> v;
    while(true) {
        if(n == 1) {
            v.push_back(n);
            break;
        }
        v.push_back(n%2);
        n = n/2;
    }
    while(!v.empty()) {
        result += to_string(v.back());
        v.pop_back();
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zeroCnt = 0;
    
    while(true) {
        string tempStr="";
        if(s == "1") {
            answer.push_back(cnt);
            answer.push_back(zeroCnt);
            break;
        }
        
        cnt += 1;
        for(char chr : s) {
            if(chr=='0') {
                zeroCnt += 1;
            } else {
                tempStr += chr;
            }
        }
        s = convertToTwo(tempStr.size());
    }
    
    return answer;
}
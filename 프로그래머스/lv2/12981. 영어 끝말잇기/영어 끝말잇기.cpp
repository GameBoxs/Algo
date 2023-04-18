#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> wordSet;
    
    int turn = 1;
    int cycle = 1;
    
    for(int i=0; i<words.size(); i++) {
        if(turn > n) {
            turn = 1;
            cycle += 1;
        }
        int beforeCnt = wordSet.size();
        wordSet.insert(words[i]);
        int afterCnt = wordSet.size();
        
        if(beforeCnt == afterCnt || (i != 0 && (words[i][0] != words[i-1][words[i-1].size()-1]))) {
            answer.push_back(turn);
            answer.push_back(cycle);
            return answer;
        }
        
        turn += 1;
    }
    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}
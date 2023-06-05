#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int basicTime = fees[0];
    int basicFee = fees[1];
    int perMin = fees[2];
    int perFee = fees[3];
    map<string, int> inM;
    map<string, int> sumM;
    
    for(int i=0; i<records.size(); i++) {
        string str = records[i];
        string inOut = str.substr(11,3);
        string carNum = str.substr(6,4);
        int totalTime = (stoi(str.substr(0,2))*60) + stoi(str.substr(3,2));
        
        if(inOut == "IN") {
            inM.insert({carNum, totalTime});
        } else {
            int inTime = inM[carNum];
            int calTime = totalTime - inTime;
            
            if(sumM.find(carNum) != sumM.end()) {
                sumM[carNum] += calTime;
            } else {
                sumM.insert({carNum, calTime});
            }
            inM.erase(carNum);
        }
    }
    if(!inM.empty()) {
        for(auto i : inM) {
            if(sumM.find(i.first) != sumM.end()) {
                sumM[i.first] += ((23 * 60) + 59) - i.second;
            } else {
                sumM.insert({i.first, ((23 * 60) + 59) - i.second});
            }
        }
    }
    
    for(auto i : sumM) {
        if(i.second <= basicTime) {
            answer.push_back(basicFee);
        } else {
            int parkingFee = basicFee + ceil((double)(i.second - basicTime)/perMin) * perFee;
            answer.push_back(parkingFee);
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> vv;
    
    s.erase(s.size()-1);
    s.erase(s.begin());
    
    string str = "";
    vector<int> tempV;
    for(char chr : s) {
        if(chr >= '0' && chr <= '9') {
            str += chr;
        } else if(chr == ',') {
            if(str.size() > 0) {
                tempV.push_back(stoi(str));
                str = "";
            }
        } else if(chr == '}') {
            tempV.push_back(stoi(str));
            vv.push_back(tempV);
            tempV.clear();
            str = "";
        }
    }
    sort(vv.begin(), vv.end(), cmp);
    
    answer.push_back(vv[0][0]);
    
    if(vv.size() > 1) {
        for(int i=1; i<vv.size(); i++) {
            for(int j=0; j<vv[i].size(); j++) {
                auto isFind = find(answer.begin(), answer.end(), vv[i][j]);
                if(isFind == answer.end()) {
                    answer.push_back(vv[i][j]);
                    break;
                }
            }
        }
    }
    
    return answer;
}
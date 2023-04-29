#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string,int> dic;

void init() {
    dic.insert({"1",0});
    int idx = 1;
    for(int i=65; i<65+26; i++) {
        string str = "";
        str += (char)i;
        dic.insert({str,idx++});
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    init();
    int idx = 27;
    for (int i = 0; i < msg.size(); i++) {
        string str = "";
        str = msg[i];
        string tempStr = str;
        bool flag = true;
        bool isInsert = false;
        for (int j = i + 1; j < msg.size(); j++) {
            if (dic[tempStr + msg[j]] == 0) {
                dic[tempStr + msg[j]] = idx++;
                if (flag)    answer.push_back(dic[str]);
                else answer.push_back(dic[tempStr]);
                i = j - 1;
                isInsert = true;
                break;
            }
            flag = false;
            tempStr += msg[j];
        }
        if (i == msg.size() - 1) {
            answer.push_back(dic[str]);
        }
        else if (!isInsert) {
            answer.push_back(dic[tempStr]);
            break;
        }
    }
    return answer;
}
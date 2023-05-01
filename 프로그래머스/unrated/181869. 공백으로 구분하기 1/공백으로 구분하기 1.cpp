#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    stringstream ss;
    ss.str(my_string);
    string temp = "";
    while(getline(ss, temp, ' ')){
        answer.push_back(temp);
    }
    return answer;
}
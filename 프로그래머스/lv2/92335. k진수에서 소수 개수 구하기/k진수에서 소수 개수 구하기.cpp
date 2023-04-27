#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
vector<long> v;
vector<bool> era;

bool is_Prime(long l) {
    if(l == 1) return false;
    
    long limitN = sqrt(l);
    for(int i=2; i<=limitN; i++) {
        if(l%i == 0) {
            return false;
        }
    }
    return true;
}

void cutStr(string str) {
    string temp = "";
    for(long i=0; i<str.size(); i++) {
        if(str[i] == '0' && temp != "") {
            v.push_back(stol(temp));
            temp = "";
            continue;
        }
        if(str[i] != '0'){
            temp += str[i];
        }
    }
    if(temp != "") {
        v.push_back(stol(temp));   
    }
}

string convertStr(int n, int k) {
    string result = "";
    while(true) {
        if(n == 1) {
            result += "1";
            break;
        }
        if(n/k == 0) {
            result += to_string(n%k);
            break;
        }
        result += to_string(n%k);
        n = n/k;
    }
    return result;
}

int solution(int n, int k) {
    int answer = 0;
    string str = convertStr(n, k);
    reverse(str.begin(), str.end());
    cutStr(str);
    for(int i=0; i<v.size(); i++) {
        if(is_Prime(v[i])) {
            answer += 1;
        }
    }
    return answer;
}
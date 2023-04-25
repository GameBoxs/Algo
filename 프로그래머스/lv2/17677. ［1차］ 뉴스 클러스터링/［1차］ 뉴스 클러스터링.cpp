#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string convertToUpper(string str) {
    string resultStr="";
    for(int i=0; i<str.size(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            resultStr += (char)(str[i]-32);
        } else {
            resultStr += str[i];
        }
    }
    return resultStr;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector <string> v1;
    vector <string> v2;
    
    str1 = convertToUpper(str1);
    str2 = convertToUpper(str2);
    
    for(int i=0; i<str1.size()-1; i++) {
        if((str1[i] >= 'A' && str1[i] <= 'Z') &&(str1[i+1] >= 'A' && str1[i+1] <= 'Z')) {
            string str = "";
            str += str1[i];
            str += str1[i+1];
            v1.push_back(str);
        }
    }
    for(int i=0; i<str2.size()-1; i++) {
        if((str2[i] >= 'A' && str2[i] <= 'Z') &&(str2[i+1] >= 'A' && str2[i+1] <= 'Z')) {
            string str = "";
            str += str2[i];
            str += str2[i+1];
            v2.push_back(str);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    vector<string> intersection(v1.size()+v2.size());
    vector<string> vUnion(v1.size()+v2.size());
    set_intersection(v2.begin(), v2.end(), v1.begin(), v1.end(), intersection.begin());
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vUnion.begin());
    
    int a = 0;
    int b = 0;
    for(string str : intersection) {
        if(str == "") break;
        a+=1;
    }
    for(string str : vUnion) {
        if(str == "") break;
        b+=1;
    }
    if(a == 0 && b == 0) {
        return 65536;
    }
    float div = (float)a/(float)b;
    answer = (int) (div*65536);
    return answer;
}
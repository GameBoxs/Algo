#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'P') {
            cnt += 1;
        } else if(s[i] == 'Y') {
            cnt -= 1;
        }
    }
    if(cnt != 0) answer = false;
    return answer;
}
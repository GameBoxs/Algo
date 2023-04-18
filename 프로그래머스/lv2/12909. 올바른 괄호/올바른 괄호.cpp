#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st;
    
    for(char chr : s) {
        if(st.empty() && chr==')') {
            answer = false;
            break;
        }
        if(chr == '(') {
            st.push(chr);
        } else {
            st.pop();
        }
    }
    if(!st.empty()) {
        answer = false;
    }

    return answer;
}
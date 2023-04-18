#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    if(s.size() == 0 || s.size() == 1) {
        return answer;
    }
    
    stack<char> st;
    
    for(char chr : s) {
        if(st.empty()) {
            st.push(chr);
        } else {
            if(chr == st.top()) {
                st.pop();
            } else {
                st.push(chr);
            }
        }
    }
    answer = st.empty() ? 1 : 0;
    return answer;
}
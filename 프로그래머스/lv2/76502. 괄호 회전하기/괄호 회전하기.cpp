#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

queue<char> q;

void init(string s) {
    for(int i=0; i<s.size(); i++) {
        q.push(s[i]);
    }
}

bool check(queue<char> copyQ) {
    stack<char> st;
    while(!copyQ.empty()) {
        char chr = copyQ.front();
        copyQ.pop();
        if(st.empty() && (chr ==')' || chr ==']' || chr =='}')) return false;
        
        if(chr =='(' || chr =='[' || chr =='{') st.push(chr);
        else if(st.top() == '(' && chr == ')') st.pop();
        else if(st.top() == '[' && chr == ']') st.pop();
        else if(st.top() == '{' && chr == '}') st.pop();
        else {
            return false;
        }
    }
    if(!st.empty()) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    init(s);
    for(int i=0; i<s.size(); i++) {
        queue<char> cq(q);
        if(check(cq)) answer += 1;
        q.push(q.front());
        q.pop();
    }
    return answer;
}
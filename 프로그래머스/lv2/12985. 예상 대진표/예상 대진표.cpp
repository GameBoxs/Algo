#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int stage = 1;
    int size = n;
    int currentN = 0;
    
    queue<int> q;
    
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    
    while(true) {
        int left = q.front();
        q.pop();
        int right = q.front();
        q.pop();
        
        currentN += 2;
        
        if((left == a || left == b) && (right == a || right == b)) {
            answer = stage;
            break;
        } else if((left == a || left == b) && (right != a && right != b)) {
            q.push(left);
        } else if((left != a && left != b) && (right == a || right == b)) {
            q.push(right);
        } else {
            q.push(left);
        }
        
        if(currentN == size) {
            size /= 2;
            stage += 1;
            currentN = 0;
        }
    }

    return answer;
}
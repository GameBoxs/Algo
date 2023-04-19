#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{   
    int ans = 0;
    
    if(n == 1 || n == 2) {
        return 1;
    }
    
    while(true) {
        if(n%2 != 0) {
            ans += 1;
            n -= 1;
        } else {
            n /= 2;
        }
        if(n == 1) {
            ans += 1;
            break;
        }
    }
    
    return ans;
}
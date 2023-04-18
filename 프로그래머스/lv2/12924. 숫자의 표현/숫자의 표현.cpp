#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i=1; i<=n/2; i++) {
        int temp = i;
        for(int j=i+1; j<=n; j++) {
            if(temp == n) {
                answer += 1;
                break;
            } else if(temp > n) {
                break;
            }
            temp += j;
        }
    }
    return answer;
}
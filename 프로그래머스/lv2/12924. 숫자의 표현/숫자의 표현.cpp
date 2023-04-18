#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // 초기 자기 자신을 포함하기 때문에 answer는 1부터 시작
    int answer = 1;
    // n나누기 2의 값을 초과한 숫자들을 연속으로 더해서는 절대 n의 값이 나오지 않음.
    // 시간을 줄이기 위해 n/2이하의 값만 돌도록 했음.
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

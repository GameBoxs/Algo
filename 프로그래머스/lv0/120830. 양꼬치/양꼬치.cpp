#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int service = (n)/10;
    k = k-service > 0 ? k-service : 0;
    int answer = (n*12000) + (k*2000);
    return answer;
}
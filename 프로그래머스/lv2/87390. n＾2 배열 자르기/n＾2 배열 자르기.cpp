#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left; i<=right; i++) {
        long long A = i/n;
        long long B = i%n;
        
        if(A > B) {
            answer.push_back(A+1);
        } else {
            answer.push_back(B+1);
        }
    }
    return answer;
}
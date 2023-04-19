#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int prevIdx = 0;
    sort(citations.begin(), citations.end());
    
    for(int i=0; i<citations[citations.size()-1]; i++) {
        if(citations[prevIdx] >= i) {
            if(citations.size()-prevIdx >= i) {
                answer = i;
            }
        } else {
            prevIdx += 1;
            i-=1;
        }
    }
    return answer;
}
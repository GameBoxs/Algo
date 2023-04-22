#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int arrSize = elements.size();
    set<int> st;
    for(int i=1; i<=arrSize; i++) {
        for(int a=0; a<arrSize; a++) {
            int sum = 0;
            for(int b=0; b<i; b++) {
                sum += elements[(a+b)%arrSize];
            }
            st.insert(sum);
        }
    }
    answer = st.size();
    return answer;
}
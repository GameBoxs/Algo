// #include <string>
// #include <vector>
// #include <set>

// using namespace std;

// int solution(vector<int> elements) {
//     int answer = 0;
//     int arrSize = elements.size();
//     set<int> st;
//     for(int i=1; i<=arrSize; i++) {
//         for(int a=0; a<arrSize; a++) {
//             int sum = 0;
//             for(int b=0; b<i; b++) {
//                 sum += elements[(a+b)%arrSize];
//             }
//             st.insert(sum);
//         }
//     }
//     answer = st.size();
//     return answer;
// }

/* 윈도우 슬라이딩으로 개선 */
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int arrSize = elements.size();
    set<int> st;
    for(int i=1; i<=arrSize; i++) {
        int sum =0;
        if(i == 1) {
            for(int j=0; j<arrSize; j++) {
                st.insert(elements[j]);
            }
        } else if(i == arrSize) {
            for(int j=0; j<arrSize; j++) {
                sum += elements[j];
            }
            st.insert(sum);
        } else {
            for(int j=0; j<i; j++) {
                sum += elements[j];
            }
            st.insert(sum);
            for(int j=0; j<arrSize-1; j++) {
                sum -= elements[j];
                sum += elements[(j+i)%arrSize];
                st.insert(sum);
            }
        }
    }
    answer = st.size();
    return answer;
}

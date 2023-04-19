#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return GCD(b, a%b);
    }
}

int solution(vector<int> arr) {
    int answer = 0;
    int A = arr[0];
    arr.erase(arr.begin());
    
    while(!arr.empty()) {
        int B = arr[0];
        arr.erase(arr.begin());
        int tempN = 0;
        if(A < B) {
            tempN = GCD(B,A);
        } else {
            tempN = GCD(A,B);
        }
        A = (A*B)/tempN;
    }
    answer = A;
    return answer;
}
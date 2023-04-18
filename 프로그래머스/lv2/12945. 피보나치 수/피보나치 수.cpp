#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v(100001, 0);

int fibo(int n) {
    if(n != 0 && v[n] != 0){
        return v[n];
    }
    if(n == 0) {
        return 0;
    } else if(n == 1){
        return 1;
    }
    
    v[n] = (fibo(n-1) + fibo(n-2))%1234567;
    return v[n];
}

int solution(int n) {
    int answer = 0;
    
    v[1] = 1;
    v[2] = 1;
    
    answer = fibo(n) % 1234567;
    cout << v[3];
    
    return answer;
}